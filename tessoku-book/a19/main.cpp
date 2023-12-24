// A19 - Knapsack 1
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
    int n, W;
    cin >> n >> W;
    vector<int> w(n+1), v(n+1);
    repi(i, 1, n+1) cin >> w[i] >> v[i];
    // 動的計画法
    vector<vector<ll>> dp(n+1, vector<ll>(W+1, -1*LLINF));
    dp[0][0] = 0;
    repi(i, 1, n+1){
        rep(j, W+1){
            if(j < w[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
        }
    }
    ll ans = -1*LLINF;
    rep(i, n+1) rep(j, W+1) ans = max(ans, dp[i][j]);
    cout << ans << el;
    return 0;
}