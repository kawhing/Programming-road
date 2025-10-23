package com.example.api.region;

import java.util.ArrayList;
import java.util.List;

public class RegionTree {
    private String city;
    private List<County> counties = new ArrayList<>();

    public RegionTree() {}
    public RegionTree(String city) { this.city = city; }

    public String getCity() { return city; }
    public void setCity(String city) { this.city = city; }
    public List<County> getCounties() { return counties; }
    public void setCounties(List<County> counties) { this.counties = counties; }
}