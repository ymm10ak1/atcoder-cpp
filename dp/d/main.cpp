// D - Knapsack 1
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
    int n, W; cin >> n >> W;
    vector<int> w(n), v(n);
    rep(i,n) cin >> w[i] >> v[i];
    vector<vector<ll>> dp(n+1,vector<ll>(W+1));
    rep(i,W+1) dp[0][i] = 0;
    repi(i,1,n+1){
        rep(j,W+1){
            if(j-w[i-1]>=0) dp[i][j] = max(dp[i-1][j-w[i-1]]+v[i-1], dp[i-1][j]); // 品物iを選ぶとき
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][W] << el;
    return 0;
}