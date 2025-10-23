<template>
  <div>
    <h1>订单查询</h1>
    <div class="address-selector">
      <label>地址：</label>
      <select v-model="selectedAddress" @change="fetchOrders">
        <option value="">全部地址</option>
        <option v-for="addr in addressOptions" :key="addr" :value="addr">{{ addr }}</option>
      </select>
      <button @click="resetAll">重置筛选</button>
    </div>
    <table border="1">
      <thead>
        <tr>
          <th>订单号</th>
          <th>快递公司</th>
          <th>收件人</th>
          <th>地址</th>
          <th>联系电话</th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="(order, index) in orders" :key="index">
          <td>{{ order.orderNumber }}</td>
          <td>{{ order.courierCompany }}</td>
          <td>{{ order.recipientName }}</td>
          <td>{{ order.address }}</td>
          <td>{{ order.phone }}</td>
        </tr>
        <tr v-if="orders.length === 0">
          <td colspan="5">暂无符合条件的订单</td>
        </tr>
      </tbody>
    </table>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      addressOptions: [],
      selectedAddress: '',
      orders: []
    };
  },
  methods: {
    fetchAddressOptions() {
      axios.get('/api/orders/all-addresses').then((response) => {
        // 假设接口返回所有订单地址数组
        this.addressOptions = response.data || [];
      });
    },
    fetchOrders() {
      axios.get('/api/orders', {
        params: {
          address: this.selectedAddress
        }
      }).then((response) => {
        this.orders = response.data || [];
      });
    },
    resetAll() {
      this.selectedAddress = '';
      this.fetchOrders();
    }
  },
  mounted() {
    this.fetchAddressOptions();
    this.fetchOrders();
  }
};
</script>