package com.example.api.controller;

import com.example.api.region.RegionTree;
import com.example.api.region.County;
import com.example.api.region.Town;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import javax.sql.DataSource;
import java.nio.file.*;
import java.sql.*;
import java.util.*;

@RestController
@RequestMapping("/api/regions")
public class RegionController {

    @Autowired
    private DataSource dataSource;

    private static final Path REGION_JSON = Paths.get("data", "regions.json");
    private final ObjectMapper objectMapper = new ObjectMapper();

    @GetMapping
    public RegionTree getRegions() {
        try {
            if (Files.exists(REGION_JSON)) {
                return objectMapper.readValue(Files.newInputStream(REGION_JSON), RegionTree.class);
            }
            try (Connection connection = dataSource.getConnection()) {
                return buildRegionTreeFromDb(connection);
            }
        } catch (Exception e) {
            e.printStackTrace();
            RegionTree fallback = new RegionTree("未知市");
            return fallback;
        }
    }

    private RegionTree buildRegionTreeFromDb(Connection connection) throws Exception {
        String sql = "SELECT DISTINCT city, county, town, village FROM orders";
        Map<String, com.example.api.region.County> countyMap = new LinkedHashMap<>();
        Map<String, Map<String, com.example.api.region.Town>> townMapByCounty = new HashMap<>();
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
}