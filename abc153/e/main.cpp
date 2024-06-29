// E - Crested Lbis vs Monster
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

// dp[i][j] : 魔法iまででモンスターの体力j削ったときの魔力消費量の総和の最小値
int dp[1005][10005];

int main(){
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n+1) rep(j,h+1) dp[i][j] = INF;
    dp[0][0] = 0;
    repi(i,1,n+1){
        rep(j,h+1){
            if(j == 0) dp[i][j] = 0;
            if(dp[i][j] >= 0){
                int d = min(j+a[i-1], h);
                dp[i][d] = min(dp[i][d], dp[i][j]+b[i-1]);
                if(i < n) dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            }
        }
    }
    cout << dp[n][h] << el;
    return 0;
}