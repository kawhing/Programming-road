package com.example.api.model.entity;

import lombok.Data;
import lombok.NoArgsConstructor;
import org.hibernate.annotations.GenericGenerator;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.Table;
import java.util.Date;

/**
 * 驿站订单统计
 */
@Data
@Entity
@NoArgsConstructor
@Table(name = "commodity")
public class Commodity {
    @Id
    @GeneratedValue(generator = "uuid2")
    @GenericGenerator(name = "uuid2", strategy = "org.hibernate.id.UUIDGenerator")
    private String id;

    @Column(name = "station_name", nullable = false)
    private String stationName;

    @Column(name = "order_count")
    private Integer orderCount;

    @Column(name = "last_in_time")
    private Date lastInTime;

    @Column(name = "description")
    private String description;
}
