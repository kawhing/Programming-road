#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 生成从 1 到 N 的所有排列
void generate_permutations(vector<string>& permutations, string current, string remaining) {
    if (remaining.empty()) {
        permutations.push_back(current);
        return;
    }
    for (size_t i = 0; i < remaining.size(); ++i) {
        generate_permutations(permutations, current + remaining[i], remaining.substr(0, i) + remaining.substr(i + 1));
    }
}

int main() {
    int N;
    string X;
    cin >> N >> X;

    // 生成初始字符串 "123...N"
    string initial;
    for (int i = 1; i <= N; ++i) {
        initial += to_string(i);
    }

    // 生成所有排列
    vector<string> permutations;
    generate_permutations(permutations, "", initial);

    // 对所有排列进行排序
    sort(permutations.begin(), permutations.end());

    // 找到给定排列的位置
    auto it = find(permutations.begin(), permutations.end(), X);
    int position = distance(permutations.begin(), it) + 1;

    // 输出结果
    cout << position << endl;

    return 0;
}