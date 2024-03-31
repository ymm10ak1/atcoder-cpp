// C - Dice Sum
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

int dp[55][2510];
const int MOD = 998244353;

int main(){
    int n, m, K;
    cin >> n >> m >> K;
    dp[0][0] = 1;
    rep(i,n){
        rep(j,K+1){
            if(dp[i][j] > 0){
                repi(k,1,m+1){
                    if(j+k <= K) dp[i+1][j+k] = (dp[i+1][j+k]+dp[i][j])%MOD;
                }
            }
        }
    }
    int ans = 0;
    rep(i,K+1) ans = (ans+dp[n][i])%MOD;
    cout << ans << el;
    return 0;
}