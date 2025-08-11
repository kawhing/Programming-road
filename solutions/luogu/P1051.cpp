#include <bits/stdc++.h>
using namespace std;

struct Student{
    string name;
    int semesterScore, classScore, thesisNum, index;
    char isStuLeader, isWestStu;
    int rewardSum = 0;
};
bool compare(Student v1, Student v2){
    if(v1.rewardSum == v2.rewardSum) return v1.index < v2.index;
    return v1.rewardSum > v2.rewardSum;
}
void solve(){
    int n, rewardsSum = 0;//学生的总数 获奖总数
    cin >> n;
    vector<Student> reward(n);//每个学生的奖金
    for(int i = 0; i < n; ++i){
        cin >> reward[i].name >> reward[i].semesterScore >> reward[i].classScore >> reward[i].isStuLeader >> reward[i].isWestStu >> reward[i].thesisNum;
        reward[i].index = i;
        if(reward[i].semesterScore > 80 && reward[i].thesisNum > 0){//期末平均成绩高于 80 分（>80），并且在本学期内发表 1 篇或 1 篇以上论文
            reward[i].rewardSum += 8000;
            rewardsSum += 8000;
        }
        if(reward[i].semesterScore > 85 && reward[i].classScore > 80){//期末平均成绩高于 85 分（>85），并且班级评议成绩高于 80 分（>80）
            reward[i].rewardSum += 4000;
            rewardsSum += 4000;
        }
        if(reward[i].semesterScore > 90){//期末平均成绩高于 90 分（>90）
            reward[i].rewardSum +=  2000;
            rewardsSum += 2000;
        }
        if(reward[i].semesterScore > 85 && reward[i].isWestStu == 'Y'){//期末平均成绩高于 85 分（>85）的西部省份学生
            reward[i].rewardSum += 1000;
            rewardsSum += 1000;
        }
        if(reward[i].classScore > 80 && reward[i].isStuLeader == 'Y'){//班级评议成绩高于 80 分（>80）的学生干部
            reward[i].rewardSum +=  850;
            rewardsSum +=  850;
        }
    }
    sort(reward.begin(), reward.end(), compare);
    cout << reward[0].name << endl;
    cout << reward[0].rewardSum << endl;
    cout << rewardsSum << endl;
}
int main(){
    solve();
    return 0;
}