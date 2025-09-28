#include "speechManager.h"
SpeechManager::SpeechManager() {
    this->initSpeech();

}
void SpeechManager::show_Menu() {
    cout << "******************************" << endl;
    cout << "**********��ӭ�μ��ݽ�����******" << endl;
    cout << "**********1.��ʼ����***********" << endl;
    cout << "**********2.�鿴�����¼********" << endl;
    cout << "**********3.��ձ�����¼********" << endl;
    cout << "**********0.�˳���������*******" << endl;
    cout << "******************************" << endl;
    cout << endl;
}
void SpeechManager::initSpeech() {
    //������ʼ��Ϊ��
    this->v1.clear();
    this->v2.clear();
    this->vectory.clear();
    this->Speakers.clear();
    //��ʼ����������
    this->index = 1;
}

void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); ++i) {
        string name = "ѡ��";
        Speaker sp;
        name += nameSeed[i];
        sp.name = name;
        for (int j = 0; j < 2; ++j) {
            sp.score[j] = 0;
        }
        //12��ѡ�ֱ��
        this->v1.push_back(i + 10001);
        this->Speakers.insert(make_pair(i + 10001, sp));
    }
}

//��ʼ���� �����������̿��ƺ���
void SpeechManager::startSpeech() {
    this->createSpeaker();
    //��һ�ֿ�ʼ����
    //1.��ǩ
    this->speechDraw();
    //2.����
    this->speechContest();
    //3.��ʾ�������
    this->showScore();

    //�ڶ��ֿ�ʼ����
    this->index++;
    //1.��ǩ
    this->speechDraw();
    //2.����
    this->speechContest();
    //3.��ʾ���ս��
    this->showScore();

    //4.����������ļ���
	this->saveRecord();
}

void SpeechManager::speechDraw() {
    cout << "�� << " << this->index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "��ǩ��ѡ��˳������: " << endl;
    if (this->index == 1) { //��һ�ֱ���
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    else { //�ڶ��ֱ���
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------------------" << endl;
    system("pause");//�����������
}

//����
void SpeechManager::speechContest() {
    cout << "---------��" << this->index << "�ֱ�����ʽ��ʼ---------" << endl;

    //��ʱ���� ���С��ĳɼ�
    multimap<double, int, greater<double>> groupScore;//����-���>
    int num = 0;//��¼С����Ա���� 6��һ��

    vector<int> vSrc;//����ѡ������
    if (this->index == 1) {
        vSrc = this->v1;
    }
    else {
        vSrc = this->v2;
    }
    //��������ѡ�ֽ��б���
    for (vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); ++it) {
        num++;
        //��ί���
        deque<double> dScore;//�����ί����������
        for (int i = 0; i < 10; ++i) {
            double socre = (rand() % 401 + 600) / 10.f;//600-1000
            //cout << "��ί" << i + 1 << "��֣�" << socre << endl;
            dScore.push_back(socre);
        }
        //cout << endl;
        sort(dScore.begin(), dScore.end(), greater<double>());//��������
        dScore.pop_back();//ȥ����߷�
        dScore.pop_front();//ȥ����ͷ�

        double sum = accumulate(dScore.begin(), dScore.end(), 0.0f);//���
        double ave = sum / (double)dScore.size();//��ƽ����

        //��ӡƽ����
        //cout << "���: " << *it << " ����: " << this->Speakers[*it].name << " �÷�: " << ave << endl;

        //��ƽ���ִ����map������
        this->Speakers[*it].score[this->index - 1] = ave;//(*it)�൱�ڱ��

        //��������� ���뵽��ʱС��������
        groupScore.insert(make_pair(ave, *it)); //key: ƽ���� value: ����ѡ�ֱ��

        //ÿ6��ȡ��ǰ����
        if (num % 6 == 0) {
            cout << "��" << num / 6 << "С���������: " << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); ++it) {
                cout << "���: " << it->second << " ����: " << this->Speakers[it->second].name << " �÷�: " << this->Speakers[it->second].score[index - 1] << endl;
            }
            //ȡǰ����
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; ++it, ++count) {
                if (this->index == 1) {
                    this->v2.push_back(it->second);//��һ�ֱ��� ��ǰ����ѡ�ֱ�ŷ���ڶ��ֱ�������
                }
                else {
                    this->vectory.push_back(it->second);//�ڶ��ֱ��� ��ǰ����ѡ�ֱ�ŷ������ձ�������
                }
            }
            groupScore.clear();//�����ʱ����
        }
    }
    cout << "---------��" << this->index << "�ֱ�������---------" << endl;
    system("pause");//�����������
}

// ��ʾ�������
void SpeechManager::showScore() {
    vector<int> v;
    if (this->index == 1) {//��һ�ֱ���
        v = this->v2;
        cout << "---------��" << this->index << "�ֱ�������ѡ����Ϣ����---------" << endl;
    }
    else {//
        v = this->vectory;
        cout << "-------------------����������Ϣ����---------------------------" << endl;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << "���: " << *it << " ����: " << this->Speakers[*it].name << " �÷�: " << this->Speakers[*it].score[index - 1] << endl;
    }
    cout << endl;
    system("pause");//�����������
    system("cls");//����
    this->show_Menu();
}

//����÷�
void SpeechManager::saveRecord() {
    //�����ļ����������
    ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//׷�ӵķ�ʽд���ļ�

    //��ѡ������д�뵽�ļ�
    for (vector<int>::iterator it = this->vectory.begin(); it != this->vectory.end(); it++) {
        ofs << *it << "," << this->Speakers[*it].name << "," << this->Speakers[*it].score[1] << ",";
    }
    ofs << endl;

    ofs.close();

	cout << "��¼����ɹ�!" << endl;
	system("pause");
	system("cls");
}

//���ص÷�
void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);

    if (!ifs.is_open()) {
        this->fileIsEmpty = true;
        cout << "�ļ������ڻ��޷���!" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "�ļ�Ϊ��!" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    
    //�ļ���Ϊ��
	this->fileIsEmpty = false;

	ifs.putback(ch);//������������ַ��Ż�ȥ
    
    string data;
    int index = 0;
    while (ifs >> data) {
        vector<string> v;

		int pos = -1;
        int start = 0;

        while (true) {
			pos = data.find(",", start);//��0��ʼ����','
            if (pos == -1) {
                break;//�Ҳ���','break��
            }
			string temp = data.substr(start, pos - start);//��ȡ�ַ���
            v.push_back(temp);
			start = pos + 1;
        }
        this->record.insert(make_pair(index, v));//���뵽�����¼map������
        index++;//��������
    }
    ifs.close();
    /*
    system("cls");
    for (map<int, vector<string>>::iterator it = this->record.begin(); it != this->record.end(); ++it) {
		cout << it->first << " �ھ����: " << it->second[0] << " " << it->second[1] << " �÷�: " << it->second[2] << endl;
    }
    */
}

//��ʾ��¼
void SpeechManager::showRecord() {
	ifstream ifs("speech.csv", ios::in);
    if(ifs.is_open()){
        ifs.close();

        for (int i = 0; i < this->record.size(); i++) {
            cout << "��" << i + 1 << "��"
                << "�ھ����: " << this->record[i][0] << " ����: " << this->record[i][1] << " �÷�: " << this->record[i][2] << endl << "     "
                << "�Ǿ����: " << this->record[i][3] << " ����: " << this->record[i][4] << " �÷�: " << this->record[i][5] << endl << "     "
                << "�������: " << this->record[i][6] << " ����: " << this->record[i][7] << " �÷�: " << this->record[i][8] << endl;
        }
    }
    else{
        if (!this->fileIsEmpty) {
            cout << "�ļ������ڻ��ļ�Ϊ��!" << endl;
        }
        return;
	}
    
    system("pause");
    system("cls");
}

//��ռ�¼
void SpeechManager::clearRecord() {
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
    cout << "0.ȡ��" << endl;
	bool clearFlag = false;
    cin >> clearFlag;

    system("cls");

    cout << "���Ҫ�������?            ��(*������*)��" << endl 
         << "�����Ļ���ʧ�ܾ�!!!       (�Τأ���)" << endl 
         << "���!                     {{{(>_<)}}}" << endl

         << "1.ȷ��                    {{{(>_<)}}}" << endl
         << "0.ȡ��" << endl;
	cin >> clearFlag;

    if (clearFlag) {
		ofstream ofs("speech.csv", ios::trunc);//ɾ���ļ�����
        ofs.close();

        //��ʼ������
        initSpeech();

		this->record.clear();//��������¼

        cout << "��ճɹ�!" << endl;
		system("pause");
		system("cls");
    }
}
//�˳�ϵͳ
void SpeechManager::exitSystem() {
    cout << "��ӭ�´�ʹ��" << endl
		<< "�ݰ�! (�����)�J" << endl;

    system("pause");
    exit(0);
}

SpeechManager::~SpeechManager() {

}