#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

void chmax(ll& a, ll b){
    if(a < b) a = b;
}


int main(){
    int n; cin >> n;
    vector<vector<int>> c(n,vector<int>(n));
    rep(i,n-1)repi(j,i+1,n){
        cin >> c[i][j];
        c[j][i] = c[i][j];
    }
    // dp[i][j]: これまで訪れた頂点の集合iの中で最後に訪れた頂点がjのときの重みの最大値
    vector dp(1<<n,vector<ll>(n,-LLINF));
    dp[0][0] = 0;
    rep(s,(1<<n)){
        int cnt = 0;
        rep(i,n) if(s>>i & 1) cnt++;
        rep(i,n){
            if(s!=0 && !(s>>i & 1)) continue;
            rep(j,n){
                if(!(s>>j & 1)){
                    int cost = 0;
                    if(cnt%2) cost = c[i][j];
                    chmax(dp[s|(1<<j)][j],dp[s][i]+cost);
                }
            }
        }
    }
    ll ans = 0;
    rep(i,n) chmax(ans,dp[(1<<n)-1][i]);
    cout << ans << el;
    return 0;
}
