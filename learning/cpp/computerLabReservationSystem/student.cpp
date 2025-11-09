#include "student.h"

//默认构造
Student::Student() {

}

//有参构造 参数: 学号 姓名 密码
Student::Student(int id, string name, string pwd) {
	//初始化属性
	this->Id = id;
	this->name = name;
	this->pwd = pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.comId >> com.maxNum) {
		this->vCom.push_back(com);
	}
	ifs.close();
}

//菜单界面
void Student::operMenu() {
	cout << "欢迎学生代表：" << this->name << "登录!" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|    1.申请预约        |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|   2.查看我的预约     |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|   3.查看所有预约     |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|     4.取消预约       |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|     0.注销登录       |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "请输入您的选择：" << endl;
}

//申请预约
void Student::applyOrder() {
	cout << "机房开放时间为周一至周五!" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;	
	cout << "5.周五" << endl;

	int date = 0;//预约日期
	int interval = 0;//预约时间段		
	int room = 0;//机房编号
	while (true) {
		cin >> date;
		if(date >=1 && date <=5) {
			break;
		}
		cout << "输入有误 请重新输入!" << endl;
	}
	cout << "请输入申请预约的时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true) {
		cin >> interval;
		if(interval == 1 || interval == 2) {
			break;
		}
		cout << "输入有误 请重新输入!" << endl;
	}
	cout << "请选择机房编号：" << endl;
	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++) {
		cout << "机房编号: " << it->comId << "\t机房最大容量: " << it->maxNum << endl;
	}
	while (true) {
		cin >> room;
		if(room == 1 || room == 2 || room == 3) {
			break;
		}
		cout << "输入有误 请重新输入!" << endl;
	}
	cout << "预约申请成功! 等待审核!" << endl;	
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " "
		<< "interval:" << interval << " "
		<< "stuId:" << this->Id << " "
		<< "stuName:" << this->name << " "
		<< "roomId:" << room << " "
		<< "status:0" << endl;
	ofs.close();
	system("pause");
	system("cls");
}

//查看我的预约
void Student::showMyOrder() {

}

//查看所有预约
void Student::showAllOrder() {

}

//取消预约
void Student::cancelOrder() {

}