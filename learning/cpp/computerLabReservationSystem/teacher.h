#pragma once
#include "identlty.h"
class Teacher :public Identlty{
public:
	//默认构造
	Teacher();

	//有参构造 教师编号 姓名 密码
	Teacher(int empId, string name, string pwd);

	//菜单界面
	virtual void operMenu();
	
	//查看所有预约
	void showAllOrder();
	
	//审核预约
	void validOrder();

	//职工号
	int empId;
	
};

