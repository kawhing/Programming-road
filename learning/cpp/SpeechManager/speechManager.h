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

    //��ʾ�˵�
    void show_Menu();

    //��ʼ������������
    void initSpeech();

    //����12��ѡ��
    void createSpeaker();

    //��ʼ����
    void startSpeech();

    //��ǩ
    void speechDraw();

    //����
    void speechContest();

    // ��ʾ�������
    void showScore();

    //����÷�
	void saveRecord();

    //���ص÷�
	void loadRecord();

    //��ʾ��¼
	void showRecord();

	//��ռ�¼
	void clearRecord();

    //�˳�ϵͳ
    void exitSystem();

    ~SpeechManager();

    vector<int> v1, v2, vectory;//��ŵ�һ�ֺ͵ڶ��ֵı��
    map<int, Speaker> Speakers;//��ű�ź�ѡ�ֵĶ�Ӧ��ϵ
    int index;//��¼��������
	bool fileIsEmpty;//�ļ��Ƿ�Ϊ��
	map<int, vector<string>> record;//��������¼
};