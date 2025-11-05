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
	//初始化容器 获取到所有文件中 学生、老师信息
	this->initVector();
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
	string fileName, tip, errorTip;

	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1) {//添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学生学号：";
		errorTip = "学号重复 请重新输入";
	}
	else {//添加教师
		fileName = TEACHER_FILE;
		tip = "请输入教师职工号：";
		errorTip = "职工号重复 请重新输入";
	}

	//利用追加的方式 写文件
	ofs.open(fileName, ios::out | ios::app);

	int id;//学号或职工号
	string name;//姓名
	string pwd;//密码

	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret) {//有重复
			cout << errorTip << endl;
		}else
			break;
	}
	
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	//向文件中添加数据
	ofs  << id << " " << name << " " << pwd << endl;
	cout << "添加成功！" << endl;

	system("pause");
	system("cls");
	ofs.close();
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

void Manager::initVector() {
	this->vStu.clear();
	this->vTea.clear();
	//读取信息 学生、老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if(!ifs.is_open()) {
		cout << "文件读取失败！" << endl;
		return;
	}

	Student s;
	while(ifs >> s.Id && ifs >> s.name && ifs >> s.pwd) {
		this->vStu.push_back(s);
	}
	cout << "当前学生数量为: " << this->vStu.size() << endl;

	ifs.close();

	//读取信息 老师
	ifs.open(TEACHER_FILE, ios::in);
	if(!ifs.is_open()) {
		cout << "文件读取失败！" << endl;
		return;
	}
	Teacher t;
	while(ifs >> t.empId && ifs >> t.name && ifs >> t.pwd) {
		this->vTea.push_back(t);
	}
	cout << "当前教师数量为: " << this->vTea.size() << endl;
	ifs.close();
}
//检测重复 参数: (传入id, 传入类型) 返回值(true 代表有重复 false代表没有重复)
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {//学生
		for(vector<Student>::iterator it = this->vStu.begin(); it != this -> vStu.end(); it++) {
			if (it->Id == id) {
				return true;
			}
		}
	}
	else {//教师
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this -> vTea.end(); it++) {
			if (it->empId == id) {
				return true;
			}
		}
	}
	return false;
}