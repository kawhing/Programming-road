#include <iostream>
#include "speechManager.h"
#include <ctime>
using namespace std;

int main() {
    //����������
	srand((unsigned int)time(NULL));
    SpeechManager sm;
//    for(map<int, Speaker>::iterator it = sm.Speakers.begin(); it != sm.Speakers.end(); it++){
//        cout << "��ţ�" << it->first << " ������" << it->second.name  << "���� " << it->second.score[0] << endl;
//    }
    int choice = 0;//�û������ѡ��
    while(true){
        sm.show_Menu();
        cout << "����������ѡ��" << endl;
        cin >> choice;
        switch (choice){
            case 1://��ʼ����
                sm.startSpeech();
                break;
            case 2://�鿴�����¼
                sm.loadRecord();
                sm.showRecord();
                break;
            case 3://��ձ�����¼
				sm.clearRecord();
                break;
            case 0://�˳�ϵͳ
                sm.exitSystem();
                break;
            default://����
                system("cls");
                break;
        }
    }
    return 0;
}
