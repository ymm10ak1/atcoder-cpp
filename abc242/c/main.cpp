// C - 1111gal password
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

const int MOD = 998244353;

int main(){
    int n; cin >> n;
    vector<vector<int>> dp(11,vector<int>(n+1,0));
    repi(i,1,10) dp[i][1] = 1;
    repi(j,2,n+1){
        repi(i,1,10){
            dp[i][j] = (((dp[i-1][j-1]+dp[i][j-1])%MOD)+dp[i+1][j-1])%MOD;
        }
    }
    int ans = 0;
    rep(i, 11) ans = (ans+dp[i][n])%MOD;
    cout << ans << el;
    return 0;
}