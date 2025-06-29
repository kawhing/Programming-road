#include <bits/stdc++.h>
using namespace std;
struct node{
    double x;
    double y;
};
void solve(){
    vector<node> point(3);
    for(int i = 0; i < 3; ++i)
        cin >> point[i].x >> point[i].y;
    double ans = 0.0;
    ans += sqrt((point[1].x-point[0].x)*(point[1].x-point[0].x) + (point[1].y-point[0].y)*(point[1].y-point[0].y));
    ans += sqrt((point[2].x-point[1].x)*(point[2].x-point[1].x) + (point[2].y-point[1].y)*(point[2].y-point[1].y));
    ans += sqrt((point[2].x-point[0].x)*(point[2].x-point[0].x) + (point[2].y-point[0].y)*(point[2].y-point[0].y));
    printf("%.2f",ans);
}
int main(){
    solve();
    return 0;
}