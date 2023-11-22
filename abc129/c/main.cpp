// C - Typical Stairs
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

const int mod = 1000000007;
map<int, bool> mpa;
vector<ll> dp;

ll rec(int i){
    if(i == 0) return 1;
    if(mpa[i]) return dp[i] = 0;
    if(dp[i] != -1) return dp[i];
    ll cnt = 0;
    if(i-1 >= 0) cnt = rec(i-1);
    if(i-2 >= 0) cnt += rec(i-2);
    cnt %= mod;
    return dp[i] = cnt;
}

int main(){
    int n, m;
    cin >> n >> m;
    dp.assign(n+1, -1);
    rep(i, m){
        int ai;
        cin >> ai;
        mpa[ai] = true;
    }
    rec(n);
    cout << dp[n] << el;
    return 0;
}