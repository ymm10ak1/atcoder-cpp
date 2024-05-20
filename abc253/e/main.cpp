// E - Dsitance Sequence
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

const int M = 998244353;
// dp[i][j]: i項目でj(1<=j<=M)を選んだときの|A_i-A_i+1|>=Kを満たす個数
int dp[1005][5005];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    dp[0][0] = 1;
    repi(i,1,n+1){
        // 累積和
        repi(j,1,m+1) dp[i-1][j] = (dp[i-1][j]+dp[i-1][j-1])%M;
        repi(j,1,m+1){
            if(i == 1){
                dp[i][j] = dp[i-1][j];
            }else{
                if(k == 0){
                    dp[i][j] = dp[i-1][m];
                    continue;
                }
                if(j+k <= m){
                    dp[i][j] = (dp[i-1][m]-dp[i-1][j+k-1])%M;
                    if(dp[i][j] < 0) dp[i][j] += M;
                }
                if(j-k >= 0){
                    dp[i][j] = (dp[i][j]+dp[i-1][j-k])%M;
                    if(dp[i][j] < 0) dp[i][j] += M;
                }
            }
        }
    }
    int ans = 0;
    rep(i,m+1) ans = (ans+dp[n][i])%M;
    cout << ans << el;
    return 0;
}
