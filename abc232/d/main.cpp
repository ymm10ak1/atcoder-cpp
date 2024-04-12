// D - Weak Takahashi
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

int dp[105][105];

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    dp[0][0] = 1;
    rep(i,h){
        rep(j,w){
            // たどり着けないマスは飛ばす
            if(dp[i][j]==0 || c[i][j]=='#') continue;
            // 今いるマスから下のマスと右のマスに移動できるなら最大のマスを比較する
            if(i+1<h && c[i+1][j]!='#') dp[i+1][j] = max(dp[i+1][j], dp[i][j]+1);
            if(j+1<w && c[i][j+1]!='#') dp[i][j+1] = max(dp[i][j+1], dp[i][j]+1);
        }
    }
    int ans = 0;
    rep(i,h) rep(j,w) ans = max(ans,dp[i][j]);
    cout << ans << el;
    return 0;
}