// D - Strange Lunchbox
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(x+1,vector<int>(y+1,INF)));
    dp[0][0][0] = 0;
    // dp[n][x][y]を試す
    rep(i,n){ // 最大300回ループ
        rep(j,x+1){ // 最大300回ループ
            rep(k,y+1){ // 最大300回ループ
                if(dp[i][j][k] == INF) continue;
                // nj,nkではなくmin(j+a[i],x),min(k+b[i],y)でいい
                int nj = j+a[i]>x?x:j+a[i];
                int nk = k+b[i]>y?y:k+b[i];
                dp[i+1][nj][nk] = min(dp[i+1][nj][nk], dp[i][j][k]+1);
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }
    if(dp[n][x][y] == INF) cout << -1 << el;
    else cout << dp[n][x][y] << el;
    return 0;
}