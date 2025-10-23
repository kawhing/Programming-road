#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "globalFile.h"
#include "identlty.h"
using namespace std;

//�������Ա�Ӳ˵�����
void managerMenu(Identlty * &person) {
	while (true) {
		//���ù���Ա�Ӳ˵�
		person->operMenu();

		//������ָ��תΪ����ָ�� ���������������ӿ�
		Manager* man = (Manager*)person;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1) {//����˺�
			cout << "����˺�" << endl;
			man->addPerson();
		}else if (select == 2) {//�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}else if (select == 3) {//�鿴������Ϣ
			cout << "�鿴������Ϣ" << endl;
			man->showComputer();
		}else if (select == 4) {//���ԤԼ��¼
			cout << "���ԤԼ��¼" << endl;
			man->cleanFile();
		}else{//�˳���¼
			delete person;//�ͷŶ�������
			person = NULL;
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	
}

//��¼���� ����1 �����ļ��� ����2 �����������
void login(string fileName, int type) {
	Identlty *person = NULL;

	//��ȡ�ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼�������û���Ϣ
	int id = 0;
	string name, pwd;

	//�ж����
	if (type == 1) {//ѧ�����
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {//��ʦ���
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1) {//ѧ�������֤
		int fId;
		string fName, fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "ѧ�������֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ�������˵�

				
				return;
			}

		}
	}
	else if (type == 2) {//��ʦ�����֤
		int fId;
		string fName, fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�����˵�


				return;
			}

		}
	}
	else if (type == 3) {//����Ա�����֤
		string fName, fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�����˵�
				managerMenu(person);

				return;
			}

		}
	}

	cout << "��֤��¼ʧ��!" << endl; 
	ifs.close();
	system("pause");
	system("cls");
}
int main() {
	while (true) {
		cout << "============================= ��ӭ�������ǲ��ͻ���ԤԼϵͳ =============================" << endl;
		cout << endl;
		cout << "�������������" << endl;
		cout << "\t\t ----------------------------------------\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              1.ѧ������                |\n";
		cout << "\t\t|                                        |\n";
        cout << "\t\t|              2.��ʦ                    |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              3.����Ա                  |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              0.�˳�                    |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t ----------------------------------------\n";
		cout << "����������ѡ��";
		int select = 0;
		cin >> select;

		switch (select) {
		case 1://ѧ�����
			login("student.txt", 1);
			break;
		case 2://��ʦ���
			login("teacher.txt", 2);
			break;
		case 3://����Ա���
			login("admin.txt", 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;

			//���������
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");

	return 0;
}