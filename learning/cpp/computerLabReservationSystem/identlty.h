#pragma once
#include <iostream>
using namespace std;

//身份抽象类
class Identlty{
public:
	//操作菜单  纯虚函数
	virtual void operMenu() = 0;
	
	string name;//用户名
	string pwd;//密码
};

