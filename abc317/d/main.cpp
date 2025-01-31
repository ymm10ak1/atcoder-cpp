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

ll dp[105][100005];

void chmin(ll& a, ll b){
    if(a > b) a = b;
}

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n), z(n);
    rep(i,n) cin >> x[i] >> y[i] >> z[i];
    rep(i,105)rep(j,100005) dp[i][j] = LLINF;
    dp[0][0] = 0;
    rep(i,n){
        rep(j,100005){
            if(dp[i][j] == LLINF) continue;
            int cost = 0;
            if(x[i] < y[i]) cost = ((x[i]+y[i])-(x[i]+y[i])/2)-x[i];
            chmin(dp[i+1][j],dp[i][j]);
            if(j+z[i] < 100005) chmin(dp[i+1][j+z[i]],dp[i][j]+cost);
        }
    }
    int zs = 0;
    rep(i,n) zs += z[i];
    ll ans = LLINF;
    repi(i,zs-zs/2,zs+1) chmin(ans, dp[n][i]);
    cout << ans << el;
    return 0;
}
