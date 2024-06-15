// D - 暑い日々(Hot days)
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

// dp[i][j]: i日目に服jを選んだときの、1~i日目までの「着る服の派手さの差の絶対値の合計」の最大値
int dp[205][205];

int main(){
    int d, n;
    cin >> d >> n;
    vector<int> t(d);
    rep(i,d) cin >> t[i];
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    rep(i,d+1) rep(j,n+1) dp[i][j] = -INF;
    // 初期値
    rep(i,n) if(a[i]<=t[0] && t[0]<=b[i]) dp[0][i] = 0;
    rep(i,d-1){
        rep(j,n){
            if(dp[i][j] >= 0){
                rep(k,n) if(a[k]<=t[i+1] && t[i+1]<=b[k]) dp[i+1][k] = max(dp[i+1][k], dp[i][j]+abs(c[j]-c[k]));
            }
        }
    }
    int ans = 0;
    rep(i,n) ans = max(ans, dp[d-1][i]);
    cout << ans << el;
    return 0;
}
