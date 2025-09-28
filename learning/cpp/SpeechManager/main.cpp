#include <iostream>
#include "speechManager.h"
#include <ctime>
using namespace std;

int main() {
    //添加随机种子
	srand((unsigned int)time(NULL));
    SpeechManager sm;
//    for(map<int, Speaker>::iterator it = sm.Speakers.begin(); it != sm.Speakers.end(); it++){
//        cout << "编号：" << it->first << " 姓名：" << it->second.name  << "分数 " << it->second.score[0] << endl;
//    }
    int choice = 0;//用户输入的选项
    while(true){
        sm.show_Menu();
        cout << "请输入您的选择：" << endl;
        cin >> choice;
        switch (choice){
            case 1://开始比赛
                sm.startSpeech();
                break;
            case 2://查看往届记录
                sm.loadRecord();
                sm.showRecord();
                break;
            case 3://清空比赛记录
				sm.clearRecord();
                break;
            case 0://退出系统
                sm.exitSystem();
                break;
            default://清屏
                system("cls");
                break;
        }
    }
    return 0;
}
