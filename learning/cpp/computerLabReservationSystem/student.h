#pragma once
#include "identlty.h"
#include <string>
#include <vector>
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"

class Student : public Identlty{
public:
	//默认构造
	Student();

	//有参构造 学号 姓名 密码
	Student(int id, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//学生学号
	int Id;

	//机房信息
	vector<ComputerRoom> vCom;
};

