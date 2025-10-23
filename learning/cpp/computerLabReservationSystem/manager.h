#pragma once
#include "identlty.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include <string>
#include <fstream>

class Manager : public Identlty{
public:
	//默认构造
	Manager();

	//有参构造
	Manager(string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();
};