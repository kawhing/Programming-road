package com.example.api.controller;

import com.example.api.model.entity.Commodity;
import com.example.api.model.support.ResponseResult;
import com.example.api.service.CommodityService;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("/api/commodity")
public class CommodityController {

    @Resource
    private CommodityService commodityService;

    @PostMapping("")
    public ResponseResult<Commodity> save(@RequestBody Commodity commodity) {
        Commodity saved = commodityService.save(commodity);
        return new ResponseResult<>(saved);
    }

    @DeleteMapping("/{id}")
    public ResponseResult<Void> delete(@PathVariable String id) {
        commodityService.delete(id);
        return new ResponseResult<>();
    }

    @PutMapping("")
    public ResponseResult<Commodity> update(@RequestBody Commodity commodity) {
        commodityService.update(commodity);
        return new ResponseResult<>(commodity);
    }

    @GetMapping("")
    public ResponseResult<List<Commodity>> findAll() {
        // Ensure order counts are up-to-date and create missing stations from orders
        commodityService.syncAndCreateOrderCounts();
        return new ResponseResult<>(commodityService.findAll());
    }

    @GetMapping("/search/{stationName}")
    public ResponseResult<List<Commodity>> findByLikeStationName(@PathVariable String stationName) {
        return new ResponseResult<>(commodityService.findAllByLikeStationName(stationName));
    }

    @GetMapping("/{id}")
    public ResponseResult<Commodity> findById(@PathVariable String id) {
        return new ResponseResult<>(commodityService.findById(id));
    }

}
