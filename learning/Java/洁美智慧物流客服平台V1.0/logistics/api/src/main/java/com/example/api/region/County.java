package com.example.api.region;

import java.util.ArrayList;
import java.util.List;

public class County {
    private String name;
    private List<Town> towns = new ArrayList<>();

    public County() {}
    public County(String name) { this.name = name; }

    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
    public List<Town> getTowns() { return towns; }
    public void setTowns(List<Town> towns) { this.towns = towns; }
}