// C - 123引き算
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
    int n; cin >> n;
    int ng[3];
    map<int, bool> mp;
    rep(i,3){
        cin >> ng[i];
        mp[ng[i]] = true;
    }
    vector<int> dp(n+1,INF);
    dp[n] = 0;
    rrepi(i,n+1,1){
        // はじめに与えられたNがngの場合終了する
        if(i == n && mp[i]) break;
        rrepi(j,4,1){
            if(i-j>=0 && !mp[i-j]){
                dp[i-j] = min(dp[i-j],dp[i]+1);
            }
        }
    }
    if(dp[0] <= 100) cout << "YES" << el;
    else cout << "NO" << el;
    return 0;
}