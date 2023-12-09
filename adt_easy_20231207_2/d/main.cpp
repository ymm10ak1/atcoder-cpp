// 
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
    int n, m;
    cin >> n >> m;
    vector<string> c(n), d(m);
    vector<int> p(m+1);
    rep(i, n) cin >> c[i];
    rep(i, m) cin >> d[i];
    rep(i, m+1) cin >> p[i];
    map<string, int> mp;
    rep(i, m){
        mp[d[i]] = p[i+1];
    }
    int ans = 0;
    rep(i, n){
        if(mp[c[i]] > 0) ans += mp[c[i]];
        else ans += p[0];
    }
    cout << ans << el;
    return 0;
}