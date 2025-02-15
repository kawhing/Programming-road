#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; ++i) {
        if (visited[i] || arr[i] == sorted_arr[i]) {
            continue;
        }

        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = find(sorted_arr.begin(), sorted_arr.end(), arr[j]) - sorted_arr.begin();
            cycle_size++;
        }

        if (cycle_size > 0) {
            swaps += (cycle_size - 1);
        }
    }

    cout << swaps << endl;
    return 0;
}