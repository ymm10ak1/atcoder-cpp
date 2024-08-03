// E - Peddler
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

int dp[200005], ep[200005];

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int>> g(n);
    rep(i,m){
        int x, y; cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
    }
    rep(i,n){ dp[i] = INF; ep[i] = -INF; }
    // 街iで買える金の最小金額を求める
    rep(i,n){
        dp[i] = min(dp[i], a[i]);
        for(int v : g[i]) dp[v] = min({dp[v], dp[i], a[v]});
    }
    // 金を売った価格と金を買った価格の差の最大値を求める
    // NOTE: 解説より利益の最大値はa[i]-dp[i]で求まる
    rep(i,n){
        for(int v: g[i]) ep[v] = max(ep[v], a[v]-dp[i]);
    }
    int ans = -INF;
    rep(i,n) ans = max(ans, ep[i]);
    cout << ans << el;
    return 0;
}