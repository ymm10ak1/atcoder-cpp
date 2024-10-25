// F
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
// dp[i][j]: i桁目でjを選んだときに条件を満たす個数
int dp[1000005][11];

int main(){
    int n; cin >> n;
    repi(i,1,10) dp[1][i] = 1;
    repi(i,1,n){
        repi(j,1,10){
            repi(k,-1,2) dp[i+1][j] = (dp[i+1][j]+dp[i][j+k])%M;
        }
    }
    int ans = 0;
    repi(i,1,10) ans = (ans+dp[n][i])%M;
    cout << ans << el;
    return 0;
}
