package com.example.api.controller;

import com.example.api.annotation.DisableBaseResponse;
import com.example.api.dto.ImportResult;
import com.example.api.dto.OrderDto;
import com.example.api.region.RegionTree;
import com.example.api.region.County;
import com.example.api.region.Town;
import com.example.api.repository.CommodityRepository;
import com.example.api.model.entity.Commodity;
import com.example.api.model.support.ResponseResult;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType; // 新增
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.sql.DataSource;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.*;

@RestController
@RequestMapping("/api/orders")
@CrossOrigin // 开发环境跨域放开
public class OrderController {

    @Autowired
    private DataSource dataSource;

    @Autowired
    private CommodityRepository commodityRepository;

    private static final Path REGION_JSON = Paths.get("data", "regions.json");
    private final ObjectMapper objectMapper = new ObjectMapper();

    @DisableBaseResponse
    @PostMapping(value = "/import", consumes = MediaType.MULTIPART_FORM_DATA_VALUE)
    public ResponseResult<ImportResult> importOrders(@RequestParam("file") MultipartFile file) {
        if (file.isEmpty()) return new ResponseResult<>(400, "文件不能为空");

        List<OrderDto> parsed = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(
                new InputStreamReader(file.getInputStream(), StandardCharsets.UTF_8));
             Connection connection = dataSource.getConnection()) {

            connection.setAutoCommit(false);

            String line;
            boolean first = true;
            while ((line = reader.readLine()) != null) {
                if (first) { // 跳过表头
                    first = false;
                    continue;
                }
                // Parse order details (CSV safe parse)
                List<String> fieldsList = parseCsvLine(line);
                if (fieldsList.size() < 8) {
                    // skip malformed line
                    continue;
                }
                String[] fields = fieldsList.toArray(new String[0]);
                String county = fields[1] == null ? "" : fields[1].trim();
                String town = fields[2] == null ? "" : fields[2].trim();
                String village = fields[3] == null ? "" : fields[3].trim();

                // Insert order into database (existing logic)
                String orderNumber = fields[0].trim();
                String courierCompany = fields[4].trim();
                String recipientName = fields[5].trim();
                String fullAddr = fields[6].trim();
                String phone = fields[7].trim();

                // Attempt to extract county/town/village from address when blank
                String city = null;
                int iCity = fullAddr.indexOf("市");
                int iCountyQ = fullAddr.indexOf("区", iCity + 1);
                int iCountyX = fullAddr.indexOf("县", iCity + 1);
                int iTownX = fullAddr.indexOf("乡", Math.max(iCountyQ, iCountyX) + 1);
                int iTownZ = fullAddr.indexOf("镇", Math.max(iCountyQ, iCountyX) + 1);
                int iVillage = fullAddr.indexOf("村", Math.max(iTownX, iTownZ) + 1);

                if (iCity > 0) city = fullAddr.substring(0, iCity + 1);
                int iCounty = (iCountyQ > -1 && iCountyX > -1) ? Math.min(iCountyQ, iCountyX) : Math.max(iCountyQ, iCountyX);
                if ((county == null || county.isEmpty()) && iCounty > -1 && iCity > -1) county = fullAddr.substring(iCity + 1, iCounty + 1);
                int iTown = (iTownX > -1 && iTownZ > -1) ? Math.min(iTownX, iTownZ) : Math.max(iTownX, iTownZ);
                if ((town == null || town.isEmpty()) && iTown > -1 && iCounty > -1) town = fullAddr.substring(iCounty + 1, iTown + 1);
                if ((village == null || village.isEmpty()) && iVillage > -1 && iTown > -1) village = fullAddr.substring(iTown + 1, iVillage + 1);

                // Construct station name from finalized parts
                String stationName = (county == null ? "" : county) + (town == null ? "" : town) + (village == null ? "" : village);

                OrderDto dto = new OrderDto();
                dto.setOrderNumber(orderNumber);
                dto.setCourierCompany(courierCompany);
                dto.setRecipientName(recipientName);
                dto.setCity(city);
                dto.setCounty(county);
                dto.setTown(town);
                dto.setVillage(village);
                dto.setAddress(fullAddr);
                dto.setPhone(phone);
                parsed.add(dto);

                // Update station order count
                try {
                    Commodity station = commodityRepository.findByStationName(stationName);
                    if (station != null) {
                        station.setOrderCount(station.getOrderCount() + 1);
                        commodityRepository.save(station);
                    }
                } catch (Exception ex) {
                    // continue on station update failure
                    ex.printStackTrace();
                }
            }

            String sql = "INSERT INTO orders (order_number, courier_company, recipient_name, city, county, town, village, address, phone) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
            try (PreparedStatement ps = connection.prepareStatement(sql)) {
                for (OrderDto row : parsed) {
                    ps.setString(1, row.getOrderNumber());
                    ps.setString(2, row.getCourierCompany());
                    ps.setString(3, row.getRecipientName());
                    ps.setString(4, row.getCity());
                    ps.setString(5, row.getCounty());
                    ps.setString(6, row.getTown());
                    ps.setString(7, row.getVillage());
                    ps.setString(8, row.getAddress());
                    ps.setString(9, row.getPhone());
                    ps.addBatch();
                }
                ps.executeBatch();
            }

            // 从 DB 构建行政区划树并写入 JSON 文件
            RegionTree tree = buildRegionTreeFromDb(connection);
            writeRegionJson(tree);

            connection.commit();

            return new ResponseResult<>(new ImportResult(parsed, tree));
        } catch (Exception e) {
            e.printStackTrace();
            return new ResponseResult<>(400, e.getMessage());
        }
    }

    @DisableBaseResponse
    @GetMapping
    public ResponseResult<List<Map<String, Object>>> getAll() {
        try (Connection connection = dataSource.getConnection();
             PreparedStatement ps = connection.prepareStatement("SELECT * FROM orders");
             ResultSet rs = ps.executeQuery()) {

            List<Map<String, Object>> orders = new ArrayList<>();
            while (rs.next()) {
                Map<String, Object> o = new HashMap<>();
                o.put("orderNumber", rs.getString("order_number"));
                o.put("courierCompany", rs.getString("courier_company"));
                o.put("recipientName", rs.getString("recipient_name"));
                o.put("city", rs.getString("city"));
                o.put("county", rs.getString("county"));
                o.put("town", rs.getString("town"));
                o.put("village", rs.getString("village"));
                o.put("address", rs.getString("address"));
                o.put("phone", rs.getString("phone"));
                orders.add(o);
            }
            return new ResponseResult<>(orders);
        } catch (Exception e) {
            e.printStackTrace();
            return new ResponseResult<>(400, e.getMessage());
        }
    }

    @DisableBaseResponse
    @GetMapping("/by-region")
    public ResponseResult<List<Map<String, Object>>> getOrdersByRegion(
            @RequestParam String city,
            @RequestParam String county,
            @RequestParam String town,
            @RequestParam String village) {
        try (Connection connection = dataSource.getConnection()) {
            String sql = "SELECT * FROM orders WHERE city = ? AND county = ? AND town = ? AND village = ?";
            try (PreparedStatement statement = connection.prepareStatement(sql)) {
                statement.setString(1, city);
                statement.setString(2, county);
                statement.setString(3, town);
                statement.setString(4, village);

                List<Map<String, Object>> orders = new ArrayList<>();
                ResultSet resultSet = statement.executeQuery();
                while (resultSet.next()) {
                    Map<String, Object> order = new HashMap<>();
                    order.put("orderNumber", resultSet.getString("order_number"));
                    order.put("courierCompany", resultSet.getString("courier_company"));
                    order.put("recipientName", resultSet.getString("recipient_name"));
                    order.put("address", resultSet.getString("address"));
                    order.put("phone", resultSet.getString("phone"));
                    orders.add(order);
                }
                return new ResponseResult<>(orders);
            }
        } catch (Exception e) {
            e.printStackTrace();
            return new ResponseResult<>(400, e.getMessage());
        }
    }

    private void writeRegionJson(RegionTree tree) throws IOException {
        Files.createDirectories(REGION_JSON.getParent());
        try (OutputStream out = Files.newOutputStream(REGION_JSON)) {
            objectMapper.writerWithDefaultPrettyPrinter().writeValue(out, tree);
        }
    }

    private RegionTree buildRegionTreeFromDb(Connection connection) throws Exception {
        String sql = "SELECT DISTINCT city, county, town, village FROM orders";
        Map<String, County> countyMap = new LinkedHashMap<>();
        Map<String, Map<String, Town>> townMapByCounty = new HashMap<>();
        String cityName = null;

        try (PreparedStatement ps = connection.prepareStatement(sql);
             ResultSet rs = ps.executeQuery()) {
            while (rs.next()) {
                String city = rs.getString("city");
                String county = rs.getString("county");
                String town = rs.getString("town");
                String village = rs.getString("village");

                if (city != null && cityName == null) cityName = city;
                if (county == null) continue;

                County countyNode = countyMap.computeIfAbsent(county, County::new);
                Map<String, Town> townMap = townMapByCounty.computeIfAbsent(county, k -> new LinkedHashMap<>());
                if (town != null) {
                    Town townNode = townMap.computeIfAbsent(town, Town::new);
                    if (village != null && !townNode.getVillages().contains(village)) {
                        townNode.getVillages().add(village);
                    }
                }
            }
        }

        RegionTree tree = new RegionTree(cityName != null ? cityName : "未知市");
        for (Map.Entry<String, County> e : countyMap.entrySet()) {
            County county = e.getValue();
            Map<String, Town> tmap = townMapByCounty.getOrDefault(e.getKey(), Collections.emptyMap());
            county.getTowns().addAll(tmap.values());
            tree.getCounties().add(county);
        }
        return tree;
    }

    // Simple CSV parser that handles quoted fields and escaped quotes
    private List<String> parseCsvLine(String line) {
        List<String> fields = new ArrayList<>();
        if (line == null) return fields;
        StringBuilder cur = new StringBuilder();
        boolean inQuotes = false;
        for (int i = 0; i < line.length(); i++) {
            char c = line.charAt(i);
            if (c == '"') {
                if (inQuotes && i + 1 < line.length() && line.charAt(i + 1) == '"') {
                    cur.append('"');
                    i++; // skip escaped quote
                } else {
                    inQuotes = !inQuotes;
                }
            } else if (c == ',' && !inQuotes) {
                fields.add(cur.toString());
                cur.setLength(0);
            } else {
                cur.append(c);
            }
        }
        fields.add(cur.toString());
        return fields;
    }
}
