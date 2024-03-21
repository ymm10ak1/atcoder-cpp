// D - Between Twwo Arrays
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
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<vector<int>> dp(n,vector<int>(3010,0));
    repi(i,a[0],b[0]+1) dp[0][i] = 1;
    // 解説見ると累積和とdpを組み合わせるみたい
    // まずdp[n][3009]を用意してdp[0][0] = 1で初期化
    // 前のiに対しての累積和を求める。for(int j=0; j<3010; j++) dp[i][j+1] = (dp[i][j+1]+dp[i][j])%MOD;
    // そのあとdp更新する(ただしi<nのとき) for(int j=a[i]; j<=b[i]; j++) dp[i+1][j] = (dp[i+1][j]+dp[i][j])%MOD;
    repi(i,1,n){
        rep(j,b[i]+1){
            if(j <= a[i]){
                dp[i][a[i]] = (dp[i][a[i]]+dp[i-1][j])%MOD;
            }else if(j <= b[i]){
                if(j > 0) dp[i][j] = (dp[i][j-1]+dp[i-1][j])%MOD;
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = 0;
    repi(i,a[n-1],b[n-1]+1) ans = (ans+dp[n-1][i])%MOD;
    cout << ans << el;
    return 0;
}