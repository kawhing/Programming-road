#pragma once
#include "identlty.h"
class Teacher :public Identlty{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι��� ��ʦ��� ���� ����
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();
	
	//�鿴����ԤԼ
	void showAllOrder();
	
	//���ԤԼ
	void validOrder();

	//ְ����
	int empId;
	
};

