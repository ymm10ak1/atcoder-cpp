// B19 - Knapsack 2
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
    const int VMAX = 100005;
    vector<vector<ll>> dp(n+1, vector<ll>(VMAX, LLINF));
    dp[0][0] = 0;
    repi(i, 1, n+1){
        rep(j, VMAX+1){
            if(j < v[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
        }
    }
    int ans = -1*INF;
    rep(i, VMAX+1){
        rep(j, n+1){
            if(dp[j][i]>=1 && dp[j][i]<=W) ans = max(ans, i);
        }
    }
    cout << ans << el;
    return 0;
}