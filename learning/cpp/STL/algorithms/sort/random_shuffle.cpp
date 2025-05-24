#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
//常用排序算法 random_shuffle
void myPrint(int val){
    cout << val << " ";
}
void test01(){
    srand((unsigned int)time(NULL));
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //利用洗牌 算法 打乱顺序
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main(){
    test01();
    return 0;
}