<template>
  <div>
    <a-table :loading="loading" :columns="columns" :data-source="data" rowKey="id">
      <template slot="action" slot-scope="text, record">
        <a-button type="link" @click="editStation(record)">编辑</a-button>
        <a-button type="link" @click="deleteStation(record.id)" style="color: #000000;">删除</a-button>
      </template>
    </a-table>
    <a-modal
      title="驿站信息"
      :closable="false"
      :visible="stationVisible"
    >
      <a-form-model ref="ruleForm" :model="station">
        <a-form-model-item label="驿站名称" prop="stationName">
          <a-input v-model="station.stationName" />
        </a-form-model-item>
        <a-form-model-item label="订单数量" prop="orderCount">
          <a-input-number v-model="station.orderCount" />
        </a-form-model-item>
        <a-form-model-item label="最后入库时间" prop="lastInTime">
          <a-date-picker v-model="station.lastInTime" show-time />
        </a-form-model-item>
      </a-form-model>
      <template slot="footer">
        <a-button @click="stationVisible = false">取消</a-button>
        <a-button type="primary" @click="saveStation">保存</a-button>
      </template>
    </a-modal>
  </div>
</template>

<script>
import axios from 'axios';
import dayjs from 'dayjs';

const columns = [
  { title: '驿站名称', dataIndex: 'stationName', key: 'stationName' },
  { title: '订单数量', dataIndex: 'orderCount', key: 'orderCount' },
  {
    title: '最后入库时间',
    dataIndex: 'lastInTime',
    key: 'lastInTime',
    customRender: (text) => {
      return text ? dayjs(text).format('YYYY-MM-DD HH:mm:ss') : '';
    }
  },
  { title: '操作', key: 'action', scopedSlots: { customRender: 'action' } },
];

export default {
  data() {
    return {
      station: {
        stationName: '',
        orderCount: 0,
        lastInTime: null,
      },
      loading: false,
      stationVisible: false,
      data: [],
      columns,
    };
  },
  mounted() {
    this.fetchStations();
  },
  methods: {
    async fetchStations() {
      this.loading = true;
      try {
        const res = await axios.get('/api/commodity');
        // 只取后端返回的 data 数组，并格式化 lastInTime
        this.data = Array.isArray(res.data.data)
          ? res.data.data.map(item => ({
              ...item,
              lastInTime: item.lastInTime ? dayjs(item.lastInTime) : null
            }))
          : [];
      } catch (e) {
        this.$message.error('加载驿站信息失败');
        this.data = [];
      }
      this.loading = false;
    },
    editStation(record) {
      this.station = {
        ...record,
        lastInTime: record.lastInTime ? dayjs(record.lastInTime) : null
      };
      this.stationVisible = true;
    },
    async deleteStation(id) {
      try {
        await axios.delete(`/api/commodity/${id}`);
        this.$message.success('删除成功');
        this.fetchStations();
      } catch (e) {
        this.$message.error('删除失败');
      }
    },
    async saveStation() {
      try {
        // 提交时将 lastInTime 转为字符串
        const submitData = {
          ...this.station,
          lastInTime: this.station.lastInTime ? dayjs(this.station.lastInTime).toISOString() : null
        };
        if (this.station.id) {
          // 编辑
          await axios.put('/api/commodity', submitData);
          this.$message.success('修改成功');
        } else {
          // 新增
          await axios.post('/api/commodity', submitData);
          this.$message.success('新增成功');
        }
        this.stationVisible = false;
        this.fetchStations();
      } catch (e) {
        this.$message.error('保存失败');
      }
    },
  },
};
</script>