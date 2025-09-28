#include "speechManager.h"
SpeechManager::SpeechManager() {
    this->initSpeech();

}
void SpeechManager::show_Menu() {
    cout << "******************************" << endl;
    cout << "**********欢迎参加演讲比赛******" << endl;
    cout << "**********1.开始比赛***********" << endl;
    cout << "**********2.查看往届记录********" << endl;
    cout << "**********3.清空比赛记录********" << endl;
    cout << "**********0.退出比赛程序*******" << endl;
    cout << "******************************" << endl;
    cout << endl;
}
void SpeechManager::initSpeech() {
    //容器初始化为空
    this->v1.clear();
    this->v2.clear();
    this->vectory.clear();
    this->Speakers.clear();
    //初始化比赛轮数
    this->index = 1;
}

void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); ++i) {
        string name = "选手";
        Speaker sp;
        name += nameSeed[i];
        sp.name = name;
        for (int j = 0; j < 2; ++j) {
            sp.score[j] = 0;
        }
        //12名选手编号
        this->v1.push_back(i + 10001);
        this->Speakers.insert(make_pair(i + 10001, sp));
    }
}

//开始比赛 比赛整个流程控制函数
void SpeechManager::startSpeech() {
    this->createSpeaker();
    //第一轮开始比赛
    //1.抽签
    this->speechDraw();
    //2.比赛
    this->speechContest();
    //3.显示晋级结果
    this->showScore();

    //第二轮开始比赛
    this->index++;
    //1.抽签
    this->speechDraw();
    //2.比赛
    this->speechContest();
    //3.显示最终结果
    this->showScore();

    //4.保存分数到文件中
	this->saveRecord();
}

void SpeechManager::speechDraw() {
    cout << "第 << " << this->index << " >> 轮比赛选手正在抽签" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "抽签后选手顺序如下: " << endl;
    if (this->index == 1) { //第一轮比赛
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    else { //第二轮比赛
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------------------" << endl;
    system("pause");//按任意键继续
}

//比赛
void SpeechManager::speechContest() {
    cout << "---------第" << this->index << "轮比赛正式开始---------" << endl;

    //临时容器 存放小组的成绩
    multimap<double, int, greater<double>> groupScore;//分数-编号>
    int num = 0;//记录小组人员个数 6人一组

    vector<int> vSrc;//比赛选手容器
    if (this->index == 1) {
        vSrc = this->v1;
    }
    else {
        vSrc = this->v2;
    }
    //遍历所有选手进行比赛
    for (vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); ++it) {
        num++;
        //评委打分
        deque<double> dScore;//存放评委分数的容器
        for (int i = 0; i < 10; ++i) {
            double socre = (rand() % 401 + 600) / 10.f;//600-1000
            //cout << "评委" << i + 1 << "打分：" << socre << endl;
            dScore.push_back(socre);
        }
        //cout << endl;
        sort(dScore.begin(), dScore.end(), greater<double>());//降序排列
        dScore.pop_back();//去掉最高分
        dScore.pop_front();//去掉最低分

        double sum = accumulate(dScore.begin(), dScore.end(), 0.0f);//求和
        double ave = sum / (double)dScore.size();//求平均分

        //打印平均分
        //cout << "编号: " << *it << " 姓名: " << this->Speakers[*it].name << " 得分: " << ave << endl;

        //将平均分存放在map容器中
        this->Speakers[*it].score[this->index - 1] = ave;//(*it)相当于编号

        //将打分数据 放入到临时小组容器中
        groupScore.insert(make_pair(ave, *it)); //key: 平均分 value: 具体选手编号

        //每6人取出前三名
        if (num % 6 == 0) {
            cout << "第" << num / 6 << "小组比赛名次: " << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); ++it) {
                cout << "编号: " << it->second << " 姓名: " << this->Speakers[it->second].name << " 得分: " << this->Speakers[it->second].score[index - 1] << endl;
            }
            //取前三名
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; ++it, ++count) {
                if (this->index == 1) {
                    this->v2.push_back(it->second);//第一轮比赛 将前三名选手编号放入第二轮比赛容器
                }
                else {
                    this->vectory.push_back(it->second);//第二轮比赛 将前三名选手编号放入最终比赛容器
                }
            }
            groupScore.clear();//清空临时容器
        }
    }
    cout << "---------第" << this->index << "轮比赛结束---------" << endl;
    system("pause");//按任意键继续
}

// 显示比赛结果
void SpeechManager::showScore() {
    vector<int> v;
    if (this->index == 1) {//第一轮比赛
        v = this->v2;
        cout << "---------第" << this->index << "轮比赛晋级选手信息如下---------" << endl;
    }
    else {//
        v = this->vectory;
        cout << "-------------------最终名次信息如下---------------------------" << endl;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << "编号: " << *it << " 姓名: " << this->Speakers[*it].name << " 得分: " << this->Speakers[*it].score[index - 1] << endl;
    }
    cout << endl;
    system("pause");//按任意键继续
    system("cls");//清屏
    this->show_Menu();
}

//保存得分
void SpeechManager::saveRecord() {
    //创建文件输出流对象
    ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//追加的方式写入文件

    //将选手数据写入到文件
    for (vector<int>::iterator it = this->vectory.begin(); it != this->vectory.end(); it++) {
        ofs << *it << "," << this->Speakers[*it].name << "," << this->Speakers[*it].score[1] << ",";
    }
    ofs << endl;

    ofs.close();

	cout << "记录保存成功!" << endl;
	system("pause");
	system("cls");
}

//加载得分
void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);

    if (!ifs.is_open()) {
        this->fileIsEmpty = true;
        cout << "文件不存在或无法打开!" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件为空!" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    
    //文件不为空
	this->fileIsEmpty = false;

	ifs.putback(ch);//将上面读到的字符放回去
    
    string data;
    int index = 0;
    while (ifs >> data) {
        vector<string> v;

		int pos = -1;
        int start = 0;

        while (true) {
			pos = data.find(",", start);//从0开始查找','
            if (pos == -1) {
                break;//找不到','break掉
            }
			string temp = data.substr(start, pos - start);//截取字符串
            v.push_back(temp);
			start = pos + 1;
        }
        this->record.insert(make_pair(index, v));//插入到往届记录map容器里
        index++;//届数自增
    }
    ifs.close();
    /*
    system("cls");
    for (map<int, vector<string>>::iterator it = this->record.begin(); it != this->record.end(); ++it) {
		cout << it->first << " 冠军编号: " << it->second[0] << " " << it->second[1] << " 得分: " << it->second[2] << endl;
    }
    */
}

//显示记录
void SpeechManager::showRecord() {
	ifstream ifs("speech.csv", ios::in);
    if(ifs.is_open()){
        ifs.close();

        for (int i = 0; i < this->record.size(); i++) {
            cout << "第" << i + 1 << "届"
                << "冠军编号: " << this->record[i][0] << " 姓名: " << this->record[i][1] << " 得分: " << this->record[i][2] << endl << "     "
                << "亚军编号: " << this->record[i][3] << " 姓名: " << this->record[i][4] << " 得分: " << this->record[i][5] << endl << "     "
                << "季军编号: " << this->record[i][6] << " 姓名: " << this->record[i][7] << " 得分: " << this->record[i][8] << endl;
        }
    }
    else{
        if (!this->fileIsEmpty) {
            cout << "文件不存在或文件为空!" << endl;
        }
        return;
	}
    
    system("pause");
    system("cls");
}

//清空记录
void SpeechManager::clearRecord() {
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
    cout << "0.取消" << endl;
	bool clearFlag = false;
    cin >> clearFlag;

    system("cls");

    cout << "真的要清除吗亲?            §(*￣▽￣*)§" << endl 
         << "清除真的会消失很久!!!       (ノへ￣、)" << endl 
         << "真的!                     {{{(>_<)}}}" << endl

         << "1.确认                    {{{(>_<)}}}" << endl
         << "0.取消" << endl;
	cin >> clearFlag;

    if (clearFlag) {
		ofstream ofs("speech.csv", ios::trunc);//删除文件内容
        ofs.close();

        //初始化属性
        initSpeech();

		this->record.clear();//清空往届记录

        cout << "清空成功!" << endl;
		system("pause");
		system("cls");
    }
}
//退出系统
void SpeechManager::exitSystem() {
    cout << "欢迎下次使用" << endl
		<< "拜拜! (￣︶￣)↗" << endl;

    system("pause");
    exit(0);
}

SpeechManager::~SpeechManager() {

}