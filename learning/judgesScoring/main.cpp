#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Person{
    public:
        Person(string name, int score){
            this->m_Name = name;
            this->m_Score = score;
        }
    string m_Name;
    int m_Score;
};
void creatPerson(vector<Person>&v){
    string nameSeed = "ABCDE";

    for(int i = 0; i < 5; ++i){
        string name = "选手";
        name += nameSeed[i];
        int score = 0;
        Person p(name, score);
        v.push_back(p);
    }
}
void setScore(vector<Person>&v){
    for(int i = 0; i < 5; ++i){
        
    }
}
int main(){
    //创建五名选手
    vector<Person> v;
    creatPerson(v);
    //测试
    for(int i = 0; i < 5; ++i){
        cout << v[i].m_Name << " " << v[i].m_Score << endl;
    }
    //给五名选手打分
    setScore(v);
    //显示最终评分
    return 0;
}