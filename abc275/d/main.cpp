// D - Yet Another Recursive Function
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

map<ll,ll> mp;

ll f(ll k){
    if(k == 0) return 1;
    if(mp[k] != 0) return mp[k];
    return mp[k] = f(k/2)+f(k/3);
}

int main(){
    ll n; cin >> n;
    cout << f(n) << el;
    return 0;
}
