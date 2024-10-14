// D - Coprime 2
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

void divisor1(ll n, map<ll,bool>& mp){
    for(ll i=1; i*i<=n; ++i){
        if(n%i == 0){
            mp[i] = true;
            if(n/i != i) mp[n/i] = true;
        }
    }
}

vector<ll> divisor2(ll n){
    vector<ll> ret;
    for(ll i=1; i*i<=n; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(n/i != i) ret.push_back(n/i);
        }
    }
    return ret;
}

int main(){
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    map<ll,bool> mp1;
    map<ll,vector<ll>> mp2;
    rep(i,n) divisor1(a[i], mp1);
    for(ll i=1; i<=m; ++i) mp2[i] = divisor2(i);
    vector<ll> ans;
    for(ll i=1; i<=m; ++i){
        bool one = true;
        rep(j,mp2[i].size()){
            if(mp2[i][j]>1 && mp1[mp2[i][j]]) one = false;
        }
        if(one) ans.push_back(i);
    }
    cout << ans.size() << el;
    rep(i,ans.size()) cout << ans[i] << el;
    return 0;
}
