#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<double> ans(3);
    double p = (3*a*c-b*b)/(3*a*a), q = (27*a*a*d-9*a*b*c+2*b*b*b)/(27*a*a*a);
    double delt = (q/2)*(q/2)+(p/3)*(p/3)*(p/3);
    
    if(delt){
        double r = 2 * sqrt(-p/3);
        double theta = acos((-q/2) / sqrt(-(p/3)*(p/3)*(p/3)));
        for(int k=0;k<3;k++){
            double t = r * cos((theta + 2*M_PI*k)/3);
            double x = t - b/(3*a);
            ans[k] = x;
        }
        sort(ans.begin(), ans.end());
        for(double res : ans)
            printf("%.2f ", res);
    }
}
