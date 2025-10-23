<template>
  <div class="import-container">
    <h1>订单导入</h1>
    <div class="upload-section">
      <input type="file" @change="handleFileUpload" accept=".csv" />
      <button @click="uploadFile">上传文件</button>
    </div>
    <table class="order-table">
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
      </tbody>
    </table>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import axios from 'axios'

const selectedFile = ref(null)
const orders = ref([])

function handleFileUpload(event) {
  selectedFile.value = event.target.files[0]
}

async function uploadFile() {
  if (!selectedFile.value) {
    alert('请先选择文件')
    return
  }
  const formData = new FormData()
  formData.append('file', selectedFile.value)
  try {
    const response = await axios.post('/api/orders/import', formData, {
      headers: { 'Content-Type': 'multipart/form-data' }
    })
    orders.value = response.data.data.orders // 假设后端返回订单列表

  } catch (error) {
    alert('文件上传失败')
  }
}
</script>

<style scoped>
.import-container { padding: 20px; font-family: Arial, sans-serif; }
.upload-section { margin-bottom: 20px; }
.upload-section input { margin-right: 10px; }
.order-table { width: 100%; border-collapse: collapse; margin-top: 20px; }
.order-table th, .order-table td { border: 1px solid #ddd; padding: 8px; text-align: left; }
.order-table th { background-color: #f4f4f4; font-weight: bold; }
.order-table tr:nth-child(even) { background-color: #f9f9f9; }
.order-table tr:hover { background-color: #f1f1f1; }
</style>