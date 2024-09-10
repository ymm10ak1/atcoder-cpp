// D - Cylinder
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int q; cin >> q;
    deque<pair<ll,int>> dq;
    rep(i,q){
        int t; cin >> t;
        if(t == 1){
            int x, c; cin >> x >> c;
            dq.push_back({x, c});
        }else{
            ll sum = 0;
            int c; cin >> c;
            while(!dq.empty() || c>0){
                auto now = dq.front();
                if(now.second >= c){
                    sum += now.first*c;
                    dq[0].second -= c;
                    c = 0;
                    if(now.second-c == 0) dq.pop_front();
                    break;
                }else{
                    sum += now.first*now.second;
                    c -= now.second;
                    dq.pop_front();
                }
            }
            cout << sum << el;
        }
    }
    return 0;
}
