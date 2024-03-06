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
    rep(i,n){
        cin >> t[i]; sum += t[i];
    }
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    dp[0][0] = true;
    repi(i,1,n+1){
        rep(j,sum+1){
            if(j-t[i] >= 0 && dp[i-1][j-t[i]]) dp[i][j] = true;
            else dp[i][j] = dp[i-1][j];
        }
    }
    int ans = INF;
    rep(i,sum+1){
        if(dp[n][i]) ans = min(ans, max(abs(sum-i), i));
    }
    cout << ans << el;
    return 0;
}