// E - Get Everything
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

// dp[i][j]: i番目までの鍵で宝箱の状態jにするための最小値
int dp[1005][4500];

void chmin(int& a, int b){
    if(a > b) a = b;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<vector<int>> c(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        rep(j,b[i]){
            int ci; cin >> ci;
            c[i].push_back(ci);
        }
    }
    rep(i,m+1)rep(j,(1<<n)) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,m){
        int cor = 0;
        rep(j,c[i].size()) cor += (1<<(c[i][j]-1));
        rep(j,(1<<n)){
            if(dp[i][j] == INF) continue;
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i+1][j|cor], dp[i][j]+a[i]);
        }
    }
    if(dp[m][(1<<n)-1] == INF) cout << -1 << el;
    else cout << dp[m][(1<<n)-1] << el;
    return 0;
}