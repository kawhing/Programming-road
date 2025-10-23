<template>
  <div class="order-table-container">
    <div class="filter-row">
      <label for="address-select">地址：</label>
      <select id="address-select" v-model="selectedAddress">
        <option value="">全部地址</option>
        <option v-for="addr in addressOptions" :key="addr" :value="addr">{{ addr }}</option>
      </select>
      <button @click="resetAll" class="reset-btn">重置筛选</button>
    </div>
    <div class="table-wrapper">
      <table class="order-table">
        <thead>
          <tr>
            <th>订单号</th>
            <th>收件人</th>
            <th>区县</th>
            <th>乡镇</th>
            <th>村</th>
            <th>详细地址</th>
            <th>联系电话</th>
            <th>状态</th>
            <th>操作</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="order in filteredOrders" :key="order.id">
            <td>{{ order.orderNumber }}</td>
            <td>{{ order.recipient }}</td>
            <td>{{ order.district }}</td>
            <td>{{ order.town }}</td>
            <td>{{ order.village }}</td>
            <td>{{ order.address }}</td>
            <td>{{ order.phone }}</td>
            <td>{{ order.status }}</td>
            <td>
              <button
                v-if="order.status !== '已签收'"
                @click="signOrder(order)"
                class="sign-btn"
              >签收</button>
              <span v-else class="signed-tip">已签收</span>
            </td>
          </tr>
          <tr v-if="filteredOrders.length === 0">
            <td colspan="9" class="no-orders">暂无符合条件的订单</td>
          </tr>
        </tbody>
      </table>
    </div>
  </div>
</template>

<script setup>
import { ref, computed, onMounted } from 'vue'

const STORAGE_KEY = 'orders_data'
const orders = ref([])

async function loadOrdersFromJson() {
  const res = await fetch('/orders.json')
  const data = await res.json()
  orders.value = data
  localStorage.setItem(STORAGE_KEY, JSON.stringify(data))
}

onMounted(async () => {
  await loadOrdersFromJson()
})

function getFullAddress(order) {
  return `${order.district}${order.town}${order.village}`
}

const selectedAddress = ref('')

const addressOptions = computed(() => {
  const set = new Set(orders.value.map(getFullAddress))
  return Array.from(set)
})

const filteredOrders = computed(() => {
  return orders.value.filter(order => {
    const fullAddr = getFullAddress(order)
    return !selectedAddress.value || fullAddr === selectedAddress.value
  })
})

const resetAll = () => {
  selectedAddress.value = ''
}

function signOrder(order) {
  order.status = '已签收'
}
</script>

<style scoped>
.order-table-container {
  max-width: 1400px;
  margin: 40px auto;
  background: #f8f9fa;
  border-radius: 12px;
  box-shadow: 0 2px 12px rgba(0,0,0,0.08);
  padding: 32px 28px;
}
.filter-row {
  display: flex;
  align-items: center;
  gap: 18px;
  margin-bottom: 18px;
}
.filter-row label {
  font-size: 16px;
  color: #555;
  font-weight: 500;
}
.filter-row select {
  min-width: 220px;
  padding: 8px 12px;
  border-radius: 5px;
  border: 1px solid #ccc;
  font-size: 15px;
  background: #fff;
}
.reset-btn {
  padding: 8px 18px;
  background: #6c757d;
  color: #fff;
  border: none;
  border-radius: 5px;
  font-size: 15px;
  cursor: pointer;
  transition: background 0.2s;
}
.reset-btn:hover {
  background: #495057;
}
.table-wrapper {
  overflow-x: auto;
}
.order-table {
  width: 100%;
  min-width: 1100px;
  border-collapse: collapse;
  background: #fff;
  border-radius: 8px;
  box-shadow: 0 1px 6px rgba(0,0,0,0.07);
}
.order-table th, .order-table td {
  padding: 12px 10px;
  border-bottom: 1px solid #eee;
  text-align: left;
  font-size: 15px;
}
.order-table th {
  background: #f1f3f6;
  font-weight: 600;
  color: #333;
}
.sign-btn {
  padding: 6px 16px;
  background: #28a745;
  color: #fff;
  border: none;
  border-radius: 4px;
  font-size: 14px;
  cursor: pointer;
  transition: background 0.2s;
}
.sign-btn:hover {
  background: #218838;
}
.signed-tip {
  color: #28a745;
  font-weight: bold;
}
.no-orders {
  text-align: center;
  color: #999;
  font-size: 16px;
  padding: 20px 0;
}
</style>