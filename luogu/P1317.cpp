#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int find(int n, vector<int> arr) {
    int result = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            ++result;
        }
    }
    return result;
}

int main() {
    ifstream infile("input.txt");
    if (!infile) {
        cerr << "Unable to open file";
        return 1;
    }

    string line;
    getline(infile, line); // 读取第一行
    int n = stoi(line);

    getline(infile, line); // 读取第二行
    istringstream iss(line);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        iss >> arr[i];
    }
    infile.close();

    cout << find(n, arr) << endl;
    return 0;
}