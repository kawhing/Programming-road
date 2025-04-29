#include <iostream>
#include <vector>
using namespace std;

// 找到下一个未被移除的卡片位置
int noTaken(const vector<bool>& taken, int start) {
    int n = taken.size();
    for (int i = start; ; i = (i + 1) % n) {
        if (!taken[i]) return i;
        if (i == (start - 1 + n) % n) break; // 如果绕了一圈还没找到，退出
    }
    return -1; // 如果没有未移除的卡片，返回 -1
}

// 计算从某个起始位置开始的得分
int winNum(const vector<int>& cards, int start) {
    int score = 0, countNum = 1;
    vector<bool> taken(cards.size(), false);
    int pos = start;

    while (true) {
        if (taken[pos]) {
            pos = noTaken(taken, pos);
            if (pos == -1) break; // 如果没有未移除的卡片，退出
        }

        if (countNum == cards[pos]) {
            score += cards[pos];
            taken[pos] = true;
            countNum = 1; // 重置数数
            pos = noTaken(taken, pos); // 移动到下一个未移除的卡片
            if (pos == -1) break; // 如果没有未移除的卡片，退出
        } else {
            countNum++;
            pos = (pos + 1) % cards.size(); // 移动到下一个卡片
        }

        if (countNum > cards.size()) break; // 如果数数超过卡片数量，退出
    }

    return score;
}

// 找到最大得分
int maxWinNum(const vector<int>& cards, int n) {
    int maxScore = 0;
    for (int i = 0; i < n; ++i) {
        maxScore = max(maxScore, winNum(cards, i));
    }
    return maxScore;
}

int main() {
    int n;
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; i++) cin >> cards[i];

    cout << maxWinNum(cards, n) << endl;
    return 0;
}