// A - Dial Up
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
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    rep(i,n) cin >> s[i];
    rep(i,m) cin >> t[i];
    bool change = false;
    int now = s[0];
    int ans = 0;
    map<int,vector<int>> mp;
    rep(i,n){
        if(s[i] == 1) mp[1].push_back(i);
        else mp[0].push_back(i);
    }
    rep(i,m){
        if(now == t[i]){
            ans++;
        }else{
            if(change){
                ans += 2;
            }else{
                change = true;
                if(mp[t[i]].size() == 0){
                    cout << -1 << el;
                    return 0;
                }
                int v1 = mp[t[i]][0];
                int v2 = mp[t[i]].back();
                int minv = min(v1,n-v2)+1;
                ans += minv;
            }
            now = t[i];
        }
    }
    cout << ans << el;
    return 0;
}
