#include "teacher.h"

//默认构造
Teacher::Teacher() {

}

//有参构造 教师编号 姓名 密码
Teacher::Teacher(int empId, string name, string pwd) {
	// 初始化属性
	this->empId = empId;
	this->name = name;
	this->pwd = pwd;
}

//菜单界面
void Teacher::operMenu() {
	cout << "欢迎教师: " << this->name << "登录!" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|    1.查看所有预约      |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|     2.审核预约       |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|     0.注销登录       |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "请输入您的选择：" << endl;
}

//查看所有预约
void Teacher::showAllOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; ++i) {
		cout << i + 1 << ". ";
		// string 转 int
		// string 利用.c_str() 转成 const char*
		// 利用 atoi(const char*) 转 int
		cout << "预约日期: 周" << of.orderData[i]["date"];
		cout << " 时间段: " << (of.orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号: " << of.orderData[i]["stuId"];
		cout << " 姓名: " << of.orderData[i]["stuName"];
		cout << " 机房号: " << of.orderData[i]["roodId"];

		string status = "状态: ";
		// 1: 审核中 2. 已预约 -1: 预约失败 0: 取消预约
		if (of.orderData[i]["status"] == "1") {
			status += "审核中";
		} else if (of.orderData[i]["status"] == "2") {
			status += "已预约";
		} else if (of.orderData[i]["status"] == "-1") {
			status += "预约失败, 审核未通过";
		} else if (of.orderData[i]["status"] == "0") {
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//审核预约
void Teacher::validOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 0;
	vector<int> v;
	cout << "待审核的预约记录如下:" << endl;
	for (int i = 0; i < of.size; ++i) {
		string date = of.orderData[i]["date"];
		string interval = of.orderData[i]["interval"];
		string stuId = of.orderData[i]["stuId"];
		string stuName = of.orderData[i]["stuName"];
		string roodId = of.orderData[i]["roodId"];
		string status = of.orderData[i]["status"];
		
		// 1: 审核中 2. 已预约 -1: 预约失败 0: 取消预约
		if (status == "1") {
			v.push_back(i);
			cout << ++index << ". ";
			cout << "预约日期: 周" << date;
			cout << " 时间段: " << (interval == "1" ? "上午" : "下午");
			cout << " 学号: " << stuId;
			cout << " 姓名: " << stuName;
			cout << " 机房号: " << roodId;
			cout << "状态: 审核中"  << endl;
		}
		cout << endl;
		cout << "请输入审核的预约记录, 0代表取消审核" << endl;
		int select = 0, ret = 0;
		while (true) {
			cin >> select;
			if (select >= 0 && select <= v.size()) {
				if (select == 0) break;
				cout << "请输入审核结果" << endl;
				cout << "1. 通过" << endl;
				cout << "2. 不通过" << endl;
				cin >> ret;
				if (ret == 1) {
					of.orderData[v[select - 1]]["status"] = "2";
				} else {
					of.orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "审核完毕" << endl;
				break;
			}
			cout << "输入有误, 请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}