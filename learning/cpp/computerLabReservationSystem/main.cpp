#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "globalFile.h"
#include "identlty.h"
using namespace std;

//进入学生子菜单界面
void studentMenu(Identlty*& student){
	while (true) {
		//调用子菜单
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;

		if (select == 1) {//申请预约
			stu->applyOrder();
		}else if(select == 2){//查看自身预约
			stu->showMyOrder();
		}else if (select == 3) { //查看所有预约
			stu->showAllOrder();
		}else if(select == 4){//取消预约
			stu->cancelOrder();
		}else {//注销登录
			delete student;//释放堆区数据
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//进入管理员子菜单界面
void managerMenu(Identlty * &person) {
	while (true) {
		//调用管理员子菜单
		person->operMenu();

		//将父类指针转为子类指针 调用子类里其他接口
		Manager* man = (Manager*)person;

		int select = 0;
		//接收用户选择
		cin >> select;

		if (select == 1) {//添加账号
			cout << "添加账号" << endl;
			man->addPerson();
		}else if (select == 2) {//查看账号
			cout << "查看账号" << endl;
			man->showPerson();
		}else if (select == 3) {//查看机房信息
			cout << "查看机房信息" << endl;
			man->showComputer();
		}else if (select == 4) {//清空预约记录
			cout << "清空预约记录" << endl;
			man->cleanFile();
		}else{//退出登录
			delete person;//释放堆区数据
			person = NULL;
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	
}

//登录功能 参数1 操作文件名 参数2 操作身份类型
void login(string fileName, int type) {
	Identlty *person = NULL;

	//读取文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接收用户信息
	int id = 0;
	string name, pwd;

	//判断身份
	if (type == 1) {//学生身份
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {//教师身份
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1) {//学生身份验证
		int fId;
		string fName, fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生身份验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生操作菜单
				studentMenu(person);
				return;
			}

		}
	}
	else if (type == 2) {//教师身份验证
		int fId;
		string fName, fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师操作菜单


				return;
			}

		}
	}
	else if (type == 3) {//管理员身份验证
		string fName, fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员操作菜单
				managerMenu(person);

				return;
			}

		}
	}

	cout << "验证登录失败!" << endl; 
	ifs.close();
	system("pause");
	system("cls");
}
int main() {
	while (true) {
		cout << "============================= 欢迎来到传智播客机房预约系统 =============================" << endl;
		cout << endl;
		cout << "请输入您的身份" << endl;
		cout << "\t\t ----------------------------------------\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              1.学生代表                |\n";
		cout << "\t\t|                                        |\n";
        cout << "\t\t|              2.老师                    |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              3.管理员                  |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              0.退出                    |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t ----------------------------------------\n";
		cout << "请输入您的选择：";
		int select = 0;
		cin >> select;

		switch (select) {
		case 1://学生身份
			login("student.txt", 1);
			break;
		case 2://教师身份
			login("teacher.txt", 2);
			break;
		case 3://管理员身份
			login("admin.txt", 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择" << endl;

			//任意键清屏
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");

	return 0;
}