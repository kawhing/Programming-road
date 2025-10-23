package com.example.api.dto;

import com.example.api.region.RegionTree;
import java.util.List;

public class ImportResult {
    private List<OrderDto> orders;
    private RegionTree regionTree;

    public ImportResult() {}
    public ImportResult(List<OrderDto> orders, RegionTree regionTree) {
        this.orders = orders;
        this.regionTree = regionTree;
    }

    public List<OrderDto> getOrders() { return orders; }
    public void setOrders(List<OrderDto> orders) { this.orders = orders; }
    public RegionTree getRegionTree() { return regionTree; }
    public void setRegionTree(RegionTree regionTree) { this.regionTree = regionTree; }
}