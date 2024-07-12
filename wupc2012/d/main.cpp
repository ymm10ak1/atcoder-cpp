// D - 三角パズル
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

// dp[i][j]: i番目の段まででj列目のときの最大値
int dp[105][105];

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n);
    rep(i,n){
        rep(j,i+1){
            int ai; cin >> ai;
            a[i].push_back(ai);
        }
    }
    rep(i,105) rep(j,105) dp[i][j] = -INF;
    dp[0][0] = a[0][0];
    rep(i,n-1){
        rep(j,101){
            if(dp[i][j] >= 0){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]+a[i+1][j]);
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+a[i+1][j+1]);
            }
        }
    }
    int ans = 0;
    rep(i,101) ans = max(ans, dp[n-1][i]);
    cout << ans << el;
    return 0;
}