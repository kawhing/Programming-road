#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> stk;
    for(int i = 0; i < 10; ++i){
        stk.push(i+1);
        cout << "入栈:" << i+1 << " 栈顶元素:" << stk.top() << " 栈大小" << stk.size() << endl;
    }
    cout << "出栈:" << stk.top();
    stk.pop();
    cout << " 栈顶元素:" << stk.top() << " 栈大小" << stk.size() << endl;
    return 0;
}