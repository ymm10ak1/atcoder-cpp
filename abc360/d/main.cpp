// D - Ghost Ants
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

// TODO: 解けてない
int main(){
    int n;
    ll t;
    string s;
    cin >> n >> t >> s;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    vector<ll> x1, x2;
    rep(i,s.size()){
        if(s[i] == '1') x1.push_back(x[i]);
        else if(s[i] == '0') x2.push_back(x[i]);
    }
    sort(all(x1));
    sort(all(x2));
    ll ans = 0;
    int l = 0, r = 0;
    rep(i,x1.size()){
        while(l<(int)x2.size() && x2[l]<x1[i]) l++;
        while(r<(int)x2.size() && x2[r]<=x1[i]+2*t) r++;
        ans += r-l;
    }
    cout << ans << el;
    return 0;
}