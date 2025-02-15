#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    // 直接运输的距离
    int direct_distance = abs(a - b);

    // 使用传送门的距离
    int teleport_distance1 = abs(a - x) + abs(y - b);
    int teleport_distance2 = abs(a - y) + abs(x - b);

    // 选择最小的距离
    int min_distance = min(direct_distance, min(teleport_distance1, teleport_distance2));

    cout << min_distance << endl;
    return 0;
}