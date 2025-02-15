#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> test = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

int countCircle(int a){
    string str = to_string(a);
    int i = 0, count = 0;
    while(str[i] != '\0'){
        count += test[str[i] -'0'];
        i++;
    }
    return count;
}

bool isBig(int &a, int &b){

    if(countCircle(a) > countCircle(b)){
        return true;
    }else if(countCircle(a) == countCircle(b)){
        return a > b;
    }
    return false;
}

// void soft(vector<int> &array){
//     for(int i = 0; i < array.size() - 1; ++i){
//         for(int j = 0; j < array.size() - i - 1; ++j){
//             if(isBig(array[j], array[j + 1])){
//                 int temp = array[j];
//                 array[j] = array[j + 1];
//                 array[j + 1] = temp;
//             }
//         }
//     }
//     for(int i = 0; i < array.size(); ++i){
//         cout << array[i] << " ";
//     }
// }

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> test = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

int countCircle(int a){
    string str = to_string(a);
    int i = 0, count = 0;
    while(str[i] != '\0'){
        count += test[str[i] -'0'];
        i++;
    }
    return count;
}

bool isBig(int &a, int &b){

    if(countCircle(a) > countCircle(b)){
        return true;
    }else if(countCircle(a) == countCircle(b)){
        return a > b;
    }
    return false;
}

void soft(vector<int> &array){
    // 先把每个数及其封闭图形个数缓存起来
    vector<pair<int,int>> info(array.size());
    for(int i = 0; i < array.size(); i++){
        info[i].first = array[i];
        info[i].second = countCircle(array[i]);
    }

    // 使用自定义比较函数进行排序
    sort(info.begin(), info.end(), [](auto &a, auto &b){
        // 封闭图形个数小的更小；如果相等，则数值较小的更小
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    // 排序结果写回，并输出
    for(int i = 0; i < array.size(); i++){
        array[i] = info[i].first;
        cout << array[i] << " ";
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    soft(array);

    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    soft(array);

    return 0;
}
