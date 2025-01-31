// 
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

// NOTE: 貪欲法でも解けるという情報をみた、自力では解けてない
int main(){
    string s;
    ll n;
    cin >> s >> n;
    vector<ll> x2;
    ll x = 1;
    rep(i,s.size()){
        x2.push_back(x);
        x *= 2;
    }
    sort(rall(x2));
    ll v = 0;
    rep(i,s.size()) if(s[i] == '1') v += x2[i];
    rep(i,s.size()) if(s[i]=='?' && v+x2[i]<=n) v += x2[i];
    ll ans = -1;
    if(v <= n) ans = v;
    cout << ans << el;
    return 0;
}
