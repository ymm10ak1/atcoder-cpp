// D
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

ll dp[200005][2][2];

template<typename T>
bool chmax(T& a, T b){
    if(a < b){ a = b; return true; }
    return false;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n+1)rep(j,2)rep(k,2) dp[i][j][k] = -LLINF;
    dp[0][0][0] = 0;
    rep(i,n){
        rep(j,2){
            rep(k,2){
                if(dp[i][j][k] == -LLINF) continue;
                // 逃げる場合
                chmax(dp[i+1][0][k], dp[i][j][k]);
                // 戦う場合
                if((k+1)%2 == 0) chmax(dp[i+1][1][(k+1)%2], dp[i][j][k]+2*a[i]);
                else chmax(dp[i+1][1][(k+1)%2], dp[i][j][k]+a[i]);
            }
        }
    }
    ll ans = -LLINF;
    rep(i,2)rep(j,2) ans = max(ans, dp[n][i][j]);
    cout << ans << el;
    return 0;
}
