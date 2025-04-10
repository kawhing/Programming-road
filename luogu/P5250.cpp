#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    vector<ll> woud;
    int t;
    cin >> t;
    while(t--){
        int op;
        cin >> op;
        if(op == 1){
            ll lenth;
            cin >> lenth;
            bool found = false;
            for(int i = 0; i < woud.size(); ++i){
            	if(lenth == woud[i]){
            		found = true;
				}
			}
            if(found) cout << "Already Exist" << endl;
            else woud.push_back(lenth);
        }else if(op == 2){
            ll lenth;
            cin >> lenth;
            if(woud.size() == 0){
                cout << "Empty" << endl;
            }else if(find(woud.begin(), woud.end(), lenth) != woud.end()){
            	auto it = find(woud.begin(), woud.end(), lenth);
                woud.erase(it);
                cout << lenth << endl;
            }else{
                sort(woud.begin(), woud.end());
                if(woud[0] > lenth){
					cout << woud[0] << endl;
					woud.erase(woud.begin());
				}else if(woud[woud.size()-1] < lenth) {
					cout << woud[woud.size()-1] << endl;
					woud.erase(woud.end()-1);
				}else{
					vector<ll> diffs(woud.size());
                	for(ll i = 0; i < woud.size(); ++i){
                		diffs[i] = abs(woud[i]-lenth);
					}
					ll index = 0;
					for(ll i = 1; i < woud.size(); ++i){
						if(diffs[index] > diffs[i]) index = i;
					}
					cout << woud[index] << endl;
					woud.erase(woud.begin()+index);
                }
            }
        }
    }
    return 0;
}