// E - Knapssack 2
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

const int V = 100001;

int main(){
    int n;
    ll W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    rep(i,n) cin >> w[i] >> v[i];
    vector<vector<ll>> dp(n+1, vector<ll>(V, LLINF));
    dp[0][0] = 0;
    repi(i,1,n+1){
        rep(j, V){
            // NOTE: dp[i-1][j-v[i-1]],dp[i-1][j]の値がLLINFかどうかの条件は無しでも良さそう
            if(j-v[i-1] >= 0){
                if(dp[i-1][j-v[i-1]] != LLINF) dp[i][j] = dp[i-1][j-v[i-1]]+w[i-1];
                if(dp[i-1][j] != LLINF) dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }else{
                if(dp[i-1][j] != LLINF) dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = 0;
    rep(i,V) if(dp[n][i] <= W) ans = i;
    cout << ans << el;
    return 0;
}