#pragma once
#include "identlty.h"

class Student : public Identlty{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι��� ѧ�� ���� ����
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int Id;
};

