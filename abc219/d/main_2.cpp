// D - Strange Lunchbox
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

int dp[305][305][305];

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n+1) rep(j,x+1) rep(k,y+1) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i,n){
        rep(j,x+1){
            rep(k,y+1){
                // 弁当iを選ばない場合
                dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
                // 弁当iを選ぶ場合
                if(dp[i][j][k] != INF){
                    int nj = min(x,j+a[i]);
                    int nk = min(y,k+b[i]);
                    dp[i+1][nj][nk] = min(dp[i+1][nj][nk], dp[i][j][k]+1);
                }
            }
        }
    }
    cout << (dp[n][x][y]!=INF ? dp[n][x][y] : -1) << el;
    return 0;
}
