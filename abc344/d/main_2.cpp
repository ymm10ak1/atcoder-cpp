#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    string t;
    int n;
    cin >> t >> n;
    vector<int> a(n);
    vector<vector<string>> s(n);
    rep(i,n){
        cin >> a[i];
        rep(j,a[i]){
            string si; cin >> si;
            s[i].push_back(si);
        }
    }
    map<string,int> dp;
    dp[""] = 0;
    rep(i,n){
        auto tmp = dp;
        for(auto [_s,p] : tmp){
            if(_s.size() == t.size()) continue;
            rep(j,a[i]){
                string ss = _s+s[i][j];
                if(ss.size() > t.size()) continue;
                if(ss.size() <= t.size()){
                    bool ok = true;
                    rep(k,ss.size()) if(ss[k] != t[k]) ok = false;
                    if(!ok) continue;
                }
                if(dp.count(ss)) dp[ss] = min(dp[ss], p+1);
                else dp[ss] = p+1;
            }
        }
    }
    if(dp.count(t)) cout << dp[t] << el;
    else cout << -1 << el;
    return 0;
}
