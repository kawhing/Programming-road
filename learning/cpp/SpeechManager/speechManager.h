#pragma once
#include <iostream>
#include <vector>
#include "Speaker.h"
#include <map>
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>
using namespace std;

class SpeechManager
{
public:
    SpeechManager();

    //显示菜单
    void show_Menu();

    //初始化容器和属性
    void initSpeech();

    //创建12名选手
    void createSpeaker();

    //开始比赛
    void startSpeech();

    //抽签
    void speechDraw();

    //比赛
    void speechContest();

    // 显示比赛结果
    void showScore();

    //保存得分
	void saveRecord();

    //加载得分
	void loadRecord();

    //显示记录
	void showRecord();

	//清空记录
	void clearRecord();

    //退出系统
    void exitSystem();

    ~SpeechManager();

    vector<int> v1, v2, vectory;//存放第一轮和第二轮的编号
    map<int, Speaker> Speakers;//存放编号和选手的对应关系
    int index;//记录比赛轮数
	bool fileIsEmpty;//文件是否为空
	map<int, vector<string>> record;//存放往届记录
};