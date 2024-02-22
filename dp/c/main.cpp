// C - Vacation
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
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dp(n,vector<int>(3,0));
    // 初期値
    dp[0][0] = a[0], dp[0][1] = b[0], dp[0][2] = c[0];
    repi(i,1,n){
        // Aを行う
        dp[i][0] = max(dp[i-1][1], dp[i-1][2])+a[i];
        // Bを行う
        dp[i][1] = max(dp[i-1][0], dp[i-1][2])+b[i];
        // Cを行う
        dp[i][2] = max(dp[i-1][0], dp[i-1][1])+c[i];
    }
    int ans = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << ans << el;
    return 0;
}