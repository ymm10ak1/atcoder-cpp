// D - Left Rihgt Operation
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

// i項目まででj(0:a[i], 1:L, 2:R)を選んだときの総和の最小値
ll dp[200005][3];

int main(){
    int n, L, R;
    cin >> n >> L >> R;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n+1) rep(j,3) dp[i][j] = LLINF;
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    repi(i,1,n+1){
        // a[i]を選ぶ場合、前の項はRにはならないのでそれ以外の中から最小のものを選ぶ
        dp[i][0] = min(dp[i-1][0], dp[i-1][1])+a[i-1];
        // Lを選ぶ場合、前の項はLしかないので前の項までのLの和にLを足す
        dp[i][1] = dp[i-1][1]+L;
        // Rを選ぶ場合、前の項はa[i],L,Rになるのでその中から最小のものを選ぶ
        dp[i][2] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]})+R;
    }
    ll ans = LLINF;
    rep(i,3) ans = min(ans, dp[n][i]);
    cout << ans << el;
    return 0;
}
