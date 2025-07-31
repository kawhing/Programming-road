#include <iostream>
#include <string>
#include <set>
#include <stack>
using namespace std;

// 判断是否为语法错误
bool isSyntaxError(string *program, int L) {
    stack<char> brackets;  // 用于检查F和E的匹配
    set<char> activeVars;  // 记录当前活跃的变量
    
    for (int i = 0; i < L; i++) {
        if (program[i][0] == 'F') {
            char var = program[i][2];
            
            // 检查变量重名
            if (activeVars.find(var) != activeVars.end()) {
                return true;  // 语法错误：变量重名
            }
            
            activeVars.insert(var);
            brackets.push(var);
        } else if (program[i][0] == 'E') {
            if (brackets.empty()) {
                return true;  // 语法错误：E没有对应的F
            }
            
            // 移除最近定义的变量
            activeVars.erase(brackets.top());
            brackets.pop();
        }
    }
    
    return !brackets.empty();  // 如果栈不为空，说明有F没有对应的E
}

// 计算复杂度
int calculateComplexity(string *program, int L) {
    int power = 0;  // 复杂度的幂次
    stack<pair<int, int>> loopStack;  // 存储循环信息：<起始行, 终止行>
    
    for (int i = 0; i < L; i++) {
        if (program[i][0] == 'F') {
            // 解析x和y
            string x, y;
            int j = 4;
            while (j < program[i].length() && program[i][j] != ' ') {
                x += program[i][j++];
            }
            j++;  // 跳过空格
            while (j < program[i].length()) {
                y += program[i][j++];
            }
            
            // 判断循环是否会执行
            bool willExecute = true;
            if (x != "n" && y != "n") {
                // 两个都是常数
                int xVal = stoi(x);
                int yVal = stoi(y);
                willExecute = (xVal <= yVal);
            }
            
            // 计算当前循环的复杂度
            int loopPower = 0;
            if (willExecute) {
                if (y == "n") {
                    loopPower = 1;  // O(n)
                }
            }
            
            loopStack.push({i, loopPower});
        } else if (program[i][0] == 'E') {
            auto [startLine, loopPower] = loopStack.top();
            loopStack.pop();
            
            // 更新总复杂度
            power += loopPower;
        }
    }
    
    return power;  // 返回复杂度的幂次，0表示O(1)
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int L;
        string complexity;
        cin >> L >> complexity;
        
        string program[L];
        for (int i = 0; i < L; i++) {
            cin >> program[i];
            // 针对F i x y的情况，读取整行
            if (program[i] == "F") {
                string var, x, y;
                cin >> var >> x >> y;
                program[i] += " " + var + " " + x + " " + y;
            }
        }
        
        // 检查语法错误
        if (isSyntaxError(program, L)) {
            cout << "ERR" << endl;
            continue;
        }
        
        // 计算复杂度
        int calculatedPower = calculateComplexity(program, L);
        
        // 解析期望的复杂度
        int expectedPower = 0;
        if (complexity != "O(1)") {
            // 从O(n^w)中提取w
            int i = 3;
            string powerStr;
            while (i < complexity.length() && complexity[i] != ')') {
                if (complexity[i] != '^') {
                    powerStr += complexity[i];
                }
                i++;
            }
            expectedPower = stoi(powerStr);
        }
        
        // 比较复杂度
        if (calculatedPower == expectedPower) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}