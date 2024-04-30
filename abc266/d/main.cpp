// D - Snuke Panic(1D)
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

int a[100005][5];

int main(){
    int n; cin >> n;
    int ti;
    rep(i,n){
        int xi, ai;
        cin >> ti >> xi >> ai;
        a[ti][xi] = ai;
    }
    vector<vector<ll>> dp(ti+1, vector<ll>(5, -LLINF));
    dp[0][0] = 0;
    rep(i,ti){
        rep(j,5){
            if(dp[i][j] == -LLINF) continue;
            // 動かない場合
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+a[i+1][j]);
            // 負の方向に移動する場合
            if(j-1 >= 0) dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]+a[i+1][j-1]);
            // 正の方向に移動する場合
            if(j+1 <= 4) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+a[i+1][j+1]);
        }
    }
    ll ans = -LLINF;
    rep(i,5) ans = max(ans, dp[ti][i]);
    cout << ans << el;
    return 0;
}