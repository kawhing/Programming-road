#pragma once
#include "identlty.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include <string>
#include <fstream>

class Manager : public Identlty{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();
};