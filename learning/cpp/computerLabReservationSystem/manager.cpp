#include "manager.h"
using namespace std;

//默认构造
Manager::Manager() {

}

//有参构造
Manager::Manager(string name, string pwd) {
	//初始化管理员信息
	this->name = name;
	this->pwd = pwd;
}

//菜单界面
void Manager::operMenu() {
	cout << "欢迎管理员：" << this->name << "登录!" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|      1.添加账号      |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|      2.查看账号      |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|    3.查看机房信息    |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|    4.清空预约记录    |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|      0.注销登录      |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "请输入您的选择：" << endl;

}

//添加账号
void Manager::addPerson() {
	cout << "请添加账号的类型：" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加教师" << endl;
	string fileName, tip;

	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1) {//添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学生学号：";
	}
	else {//添加教师
		fileName = TEACHER_FILE;
		tip = "请输入教师职工号：";
	}

}

//查看账号
void Manager::showPerson() {

}

//查看机房信息
void Manager::showComputer() {

}

//清空预约记录
void Manager::cleanFile() {

}