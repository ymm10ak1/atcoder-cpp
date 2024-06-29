// A - Two Abbreviations
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

ll gcd(ll x, ll y){
    if(y == 0) return x;
    else return gcd(y, x%y);
}

ll lcm(ll x, ll y){
    return x / gcd(x, y) * y;
}

int main(){
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    ll lc = lcm(n, m);
    ll ln = lc/n, lm = lc/m;
    map<ll, char> mp;
    for(ll i=0; i<n; ++i) mp[i*ln+1] = s[i];
    bool ok = true;
    for(ll i=0; i<m; ++i){
        if(mp.find(i*lm+1) != mp.end()){
            if(mp[i*lm+1] != t[i]) ok = false;
        }else{
            mp[i*lm+1] = t[i];
        }
    }
    if(ok) cout << lc << el;
    else cout << -1 << el;
    return 0;
}
