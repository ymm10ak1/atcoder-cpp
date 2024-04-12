// D - Flipping and Bonus
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

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    map<int,int> mp;
    rep(i,m){
        int c, y;
        cin >> c >> y;
        mp[c] = y;
    }
    // i回目のコイントスでカウンタがjになるときの金額の最大値
    vector<vector<ll>> dp(n+1, vector<ll>(n+1,-1));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,n){
            if(dp[i][j] >= 0){
                dp[i+1][0] = max(dp[i+1][0], dp[i][j]);
                dp[i+1][j+1] = dp[i][j]+x[i]+mp[j+1];
            }
        }
    }
    ll ans = 0;
    rep(i,n+1) ans = max(ans, dp[n][i]);
    cout << ans << el;
    return 0;
}