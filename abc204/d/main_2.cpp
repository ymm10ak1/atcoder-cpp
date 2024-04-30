// D - Cooking
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
    vector<int> t(n);
    int sum = 0;
    rep(i,n){ cin >> t[i]; sum += t[i]; }
    vector<vector<int>> dp(n+1, vector<int>(sum+1,-INF));
    dp[0][0] = sum;
    rep(i,n){
        rep(j,sum+1){
            if(dp[i][j] == -INF) continue;
            dp[i+1][j] = dp[i][j];
            if(j+t[i] <= sum) dp[i+1][j+t[i]] = dp[i][j]-t[i];
        }
    }
    int ans = INF;
    rep(i,sum+1) if(dp[n][i] != -INF) ans = min(ans, max(dp[n][i], i));
    cout << ans << el;
    return 0;
}