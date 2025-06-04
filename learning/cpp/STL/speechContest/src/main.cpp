#include "../include/manage.h"
#include <windows.h>
using namespace std;
int main(){
    // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int choice = 0;
    Manage manage;
    while(true){
        manage.showMenu();
        cout << "请输入你的选择: ";
        cin >> choice;
        switch(choice){
            case 1: //开始比赛
                break;
            case 2: //查看记录
                break;
            case 3: //清空记录
                break;
            case 0: //退出系统
                manage.exitSystem();
                break;
            default:
                system("cls");
                break;
        }
    }
    system("pause");
    return 0;
}