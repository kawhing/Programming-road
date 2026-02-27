#include "orderFile.h"

OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;//日期
	string interval;//时间段
	string stuId;//学号
	string stuName;//姓名
	string roomId;//机房号
	string status;//预约状态

	this->size = 0;

	while (ifs >> date >> interval >> stuId >> stuName >> roomId >> status) {
		string key, value;
		map<string, string> m;
		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - 1 - pos);
		}
		m.insert(make_pair(key, value));
		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - 1 - pos);
		}
		m.insert(make_pair(key, value));

		pos = stuId.find(":");
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - 1 - pos);
		}
		m.insert(make_pair(key, value));

		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - 1 - pos);
		}
		m.insert(make_pair(key, value));

		pos = roomId.find(":");
		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - 1 - pos);
		}
		m.insert(make_pair(key, value));

		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - 1 - pos);
		}
		m.insert(make_pair(key, value));
		this->orderData.insert(make_pair(this->size, m));
		this->size++;
	}
}
void OrderFile::updateOrder() {
	if(this->size == 0) return;
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->size; ++i) {
		ofs << "date:" << this->orderData[i]["date"] << " ";
		ofs << "interval:" << this->orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->orderData[i]["roomId"] << " ";
		ofs	<< "status:" << this->orderData[i]["status"] << endl;
	}
	ofs.close();
}