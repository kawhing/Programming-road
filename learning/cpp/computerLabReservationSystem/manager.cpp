#include "manager.h"
using namespace std;

//Ĭ�Ϲ���
Manager::Manager() {

}

//�вι���
Manager::Manager(string name, string pwd) {
	//��ʼ������Ա��Ϣ
	this->name = name;
	this->pwd = pwd;
}

//�˵�����
void Manager::operMenu() {
	cout << "��ӭ����Ա��" << this->name << "��¼!" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|      1.����˺�      |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|      2.�鿴�˺�      |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|    3.�鿴������Ϣ    |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|    4.���ԤԼ��¼    |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t|      0.ע����¼      |" << endl;
	cout << "\t\t|                      |" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "����������ѡ��" << endl;

}

//����˺�
void Manager::addPerson() {
	cout << "������˺ŵ����ͣ�" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.��ӽ�ʦ" << endl;
	string fileName, tip;

	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1) {//���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ��ѧ�ţ�";
	}
	else {//��ӽ�ʦ
		fileName = TEACHER_FILE;
		tip = "�������ʦְ���ţ�";
	}

}

//�鿴�˺�
void Manager::showPerson() {

}

//�鿴������Ϣ
void Manager::showComputer() {

}

//���ԤԼ��¼
void Manager::cleanFile() {

}