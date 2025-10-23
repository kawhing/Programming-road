package com.example.api.service.impl;

import com.example.api.model.entity.Commodity;
import com.example.api.repository.CommodityRepository;
import com.example.api.service.CommodityService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Service
public class CommodityServiceImpl implements CommodityService {

    @Resource
    private CommodityRepository commodityRepository;

    @Resource
    private DataSource dataSource;

    @Override
    public Commodity save(Commodity commodity) {
        return commodityRepository.save(commodity);
    }

    @Override
    public void update(Commodity commodity) {
        commodityRepository.save(commodity);
    }

    @Override
    public void delete(String id) {
        commodityRepository.deleteById(id);
    }

    @Override
    public Commodity findById(String id) {
        return commodityRepository.findById(id).orElse(null);
    }

    @Override
    public List<Commodity> findAll() {
        return commodityRepository.findAll();
    }

    @Override
    public List<Commodity> findAllByLikeStationName(String stationName) {
        return commodityRepository.findByStationNameLike("%" + stationName + "%");
    }

    @Override
    public void syncOrderCounts() {
        // compute counts grouped by county+town+village via JDBC
        Map<String, Integer> counts = new HashMap<>();
        String sql = "SELECT county, town, village, COUNT(*) cnt FROM orders GROUP BY county, town, village";
        try (Connection conn = dataSource.getConnection();
             PreparedStatement ps = conn.prepareStatement(sql);
             ResultSet rs = ps.executeQuery()) {
            while (rs.next()) {
                String county = rs.getString("county");
                String town = rs.getString("town");
                String village = rs.getString("village");
                county = county == null ? "" : county.trim();
                town = town == null ? "" : town.trim();
                village = village == null ? "" : village.trim();
                String stationName = (county + town + village).replaceAll("\\s+", " ").trim();
                int cnt = rs.getInt("cnt");
                counts.put(stationName, cnt);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        List<Commodity> stations = commodityRepository.findAll();
        for (Commodity station : stations) {
            String key = station.getStationName() == null ? "" : station.getStationName().trim().replaceAll("\\s+"," ");
            int count = counts.getOrDefault(key, 0);
            station.setOrderCount(count);
            commodityRepository.save(station);
        }
    }

    @Override
    public void syncAndCreateOrderCounts() {
        // Aggregate orders grouped by county,town,village and ensure commodity rows exist
        Map<String, Integer> counts = new HashMap<>();
        String sql = "SELECT county, town, village, COUNT(*) cnt FROM orders GROUP BY county, town, village";
        try (Connection conn = dataSource.getConnection()) {
            System.out.println("Database connection established successfully.");
            try (PreparedStatement ps = conn.prepareStatement(sql);
                 ResultSet rs = ps.executeQuery()) {
                System.out.println("SQL query executed: " + sql);
                while (rs.next()) {
                    String county = rs.getString("county");
                    String town = rs.getString("town");
                    String village = rs.getString("village");
                    county = county == null ? "" : county.trim();
                    town = town == null ? "" : town.trim();
                    village = village == null ? "" : village.trim();
                    String stationName = (county + town + village).replaceAll("\\s+"," ").trim();
                    int cnt = rs.getInt("cnt");
                    counts.put(stationName, cnt);
                    System.out.println("Aggregated station: " + stationName + ", count: " + cnt);
                }
            }
        } catch (Exception e) {
            System.err.println("Error executing SQL query: " + sql);
            e.printStackTrace();
            throw new RuntimeException("Failed to aggregate orders: " + e.getMessage(), e);
        }

        List<Commodity> stations = commodityRepository.findAll();
        Map<String, Commodity> map = new HashMap<>();
        for (Commodity c : stations) map.put(c.getStationName(), c);

        Date now = new Date();
        for (Map.Entry<String, Integer> e : counts.entrySet()) {
            String stationName = e.getKey();
            int cnt = e.getValue();
            Commodity c = map.get(stationName);
            if (c == null) {
                c = new Commodity();
                c.setStationName(stationName);
                c.setOrderCount(cnt);
                c.setLastInTime(now);
                commodityRepository.save(c);
            } else {
                c.setOrderCount(cnt);
                c.setLastInTime(now);
                commodityRepository.save(c);
            }
        }
    }
}
