// B39 - Taro's Job
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> x(n), y(n);
    map<int, priority_queue<int>> mp;
    rep(i, n){
        cin >> x[i] >> y[i];
        mp[x[i]].push(y[i]);
    }
    ll ans = 0;
    repi(i, 1, d+1){
        int current_max = 0, max_idx = 0;
        bool check = false;
        // i日目までの最大値を探す
        repi(j, 1, i+1){
            if(mp[j].size() != 0){
                if(current_max < mp[j].top()){
                    current_max = mp[j].top();
                    max_idx = j;
                    check = true;
                }
            }
        }
        ans += current_max;
        if(check) mp[max_idx].pop();
    }
    cout << ans << el;
    return 0;
}