#include <iostream>
#include <vector>
using namespace std;

int n = 2, m = 6;
typedef struct Task{
    int a; // 分配时刻
    int b; // 指定计算机编号
    int c; // 耗时
    int d; // 算力消耗
}Task;
vector<Task> tasks(n);
vector<vector<int>> computer;
void initComputer(){
    
    for(int i = 0; i < n; ++i){
        //cin >> computer[i][0];
        computer[i][0] = 5;//初始化算力
        computer[i][1] = 0;//剩余时间为0
    }
}
int getTime(int b){
    if(computer[b-1][1] > 0){//如果计算机有任务
        return computer[b-1][1];//返回剩余时间
    }
    return 0;//如果计算机没有任务
}

void changeTime(){
    for(int i = 0; i < n; ++i){
        if(computer[i][1]){
            computer[i][1]--;
        }
    }
}
int main(){
    n = 2, m = 6;//计算机数目和要分配的任务数
    //cin >> n >> m;
    tasks.resize(m);
    computer.resize(n, vector<int>(2));//算力,剩余时间
        for (int i = 0; i < n; ++i) {
        cin >> computer[i][0]; // 初始化每台计算机的算力
    }
    initComputer();
    tasks = {{1, 1, 5, 3}, {2, 2, 2, 6}, {3, 1, 2, 3}, {4, 1, 6, 1}, {5, 1, 3, 3}, {6, 1, 3, 4}};
    //for(int i = 0; i < m; ++i){
    //    cin >> tasks[i].a >> tasks[i].b >> tasks[i].c >> tasks[i].d;
    //}
    //第 i 个任务在 ai 时刻分配，指定计算机编号为 bi, 耗时为 ci 且算力消耗为 di
    //
    //tasks = {{1, 1, 5, 3}, {2, 2, 2, 6}, {3, 1, 2, 3}, {4, 1, 6, 1}, {5, 1, 3, 3}, {6, 1, 3, 4}};
    for(int i = 0; i < m; ++i){
        changeTime();//循环判断计算机是否分配了任务,并且更新剩余时间
        if(getTime(tasks[i].b)){//如果任务i分配给了有任务的计算机
            cout << "-1" << endl;
        }else{//如果任务i没有分配给有任务的计算机
            if(computer[(tasks[i].b)-1][0] >= tasks[i].d){//当前计算机剩余算力大于等于任务i的算力消耗
                cout << computer[(tasks[i].b)-1][0]-tasks[i].d << endl;//输出剩余算力
                computer[(tasks[i].b)-1][1] = tasks[i].c;//更新计算机剩余时间
                
            }else{
                cout << "-1" << endl;
            }
        }
    }
        
    return 0;
}