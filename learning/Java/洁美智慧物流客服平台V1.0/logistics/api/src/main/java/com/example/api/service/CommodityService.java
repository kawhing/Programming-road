package com.example.api.service;

import com.example.api.model.entity.Commodity;

import java.util.List;

public interface CommodityService {

    Commodity save(Commodity commodity);

    void update(Commodity commodity);

    void delete(String id);

    Commodity findById(String id);

    List<Commodity> findAll();

    List<Commodity> findAllByLikeStationName(String stationName);

    void syncOrderCounts();

    /**
     * Aggregate orders and ensure each station exists in commodity table; create missing stations and set orderCount.
     */
    void syncAndCreateOrderCounts();
}
