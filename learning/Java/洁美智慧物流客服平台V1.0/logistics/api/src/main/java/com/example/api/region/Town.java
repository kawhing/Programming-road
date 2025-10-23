package com.example.api.region;

import java.util.ArrayList;
import java.util.List;

public class Town {
    private String name;
    private List<String> villages = new ArrayList<>();

    public Town() {}
    public Town(String name) { this.name = name; }

    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
    public List<String> getVillages() { return villages; }
    public void setVillages(List<String> villages) { this.villages = villages; }
}