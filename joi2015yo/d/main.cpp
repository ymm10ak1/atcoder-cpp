// D - シルクロード(Silk Road)
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

// dp[i][j]: 都市iにj日目に着いたときの疲労度の合計の最小値
int dp[1005][1005];

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    vector<int> c(m);
    rep(i,m) cin >> c[i];
    rep(i,n+1) rep(j,m+1) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,n){
        rep(j,m){
            if(dp[i][j] != INF){
                repi(k,j+1,m+1) dp[i+1][k] = min(dp[i+1][k], dp[i][j]+d[i]*c[k-1]);
            }
        }
    }
    int ans = INF;
    rep(i,m+1) ans = min(ans, dp[n][i]);
    cout << ans << el;
    return 0;
}
