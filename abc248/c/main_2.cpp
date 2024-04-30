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

const int MOD = 998244353;
// 数列の先頭からi項までで総和jを作れる個数
int dp[55][2505];

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    // このfor文での処理もまとめられる
    // repi(i,1,m+1) dp[0][i] = 1;

    // 0項までで0を作れる個数は1個
    dp[0][0] = 1;
    rep(i,n){
        rep(j,k+1){
            if(dp[i][j] >= 1){
                repi(l,1,m+1) if(j+l <= k) dp[i+1][j+l] = (dp[i+1][j+l]+dp[i][j])%MOD;
            }
        }
    }
    int ans = 0;
    rep(i,k+1) ans = (ans+dp[n][i])%MOD;
    cout << ans << el;
    return 0;
}