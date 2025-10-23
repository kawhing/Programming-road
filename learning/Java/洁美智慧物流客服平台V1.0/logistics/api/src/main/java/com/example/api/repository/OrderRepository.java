package com.example.api.repository;

import com.example.api.model.entity.Order;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

public interface OrderRepository extends JpaRepository<Order, String> {

    @Query("SELECT COUNT(o) FROM Order o WHERE o.stationName = :stationName")
    int countByStationName(@Param("stationName") String stationName);

}
