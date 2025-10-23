package com.example.api.dto;

public class OrderDto {
    private String orderNumber;
    private String courierCompany;
    private String recipientName;
    private String city;
    private String county;
    private String town;
    private String village;
    private String address;
    private String phone;

    // getters and setters
    public String getOrderNumber() { return orderNumber; }
    public void setOrderNumber(String orderNumber) { this.orderNumber = orderNumber; }
    public String getCourierCompany() { return courierCompany; }
    public void setCourierCompany(String courierCompany) { this.courierCompany = courierCompany; }
    public String getRecipientName() { return recipientName; }
    public void setRecipientName(String recipientName) { this.recipientName = recipientName; }
    public String getCity() { return city; }
    public void setCity(String city) { this.city = city; }
    public String getCounty() { return county; }
    public void setCounty(String county) { this.county = county; }
    public String getTown() { return town; }
    public void setTown(String town) { this.town = town; }
    public String getVillage() { return village; }
    public void setVillage(String village) { this.village = village; }
    public String getAddress() { return address; }
    public void setAddress(String address) { this.address = address; }
    public String getPhone() { return phone; }
    public void setPhone(String phone) { this.phone = phone; }
}