// A - Range Flip Find Route
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

// dp[i][j]: マス(i,j)にたどり着くまでの最小回数
int dp[105][105];

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    // 問題を読み間違えていた
    rep(i,105) rep(j,105) dp[i][j] = INF;
    dp[0][0] = s[0][0]=='#' ? 1 : 0;
    rep(i,h){
        rep(j,w){
            if(i > 0 && j > 0){
                if(s[i][j] == '#'){
                    // 1つ左または上のマスが黒色の場合、つながっているのでまとめて白色に変更可能
                    if(s[i-1][j] == '#') dp[i][j] = min(dp[i][j], dp[i-1][j]);
                    else dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                    if(s[i][j-1] == '#') dp[i][j] = min(dp[i][j], dp[i][j-1]);
                    else dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                }
            }else if(i == 0 && j > 0){
                if(s[i][j] == '#'){
                    if(s[i][j-1] == '#') dp[i][j] = dp[i][j-1];
                    else dp[i][j] = dp[i][j-1]+1;
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }else if(j == 0 && i > 0){
                if(s[i][j] == '#'){
                    if(s[i-1][j] == '#') dp[i][j] =dp[i-1][j];
                    else dp[i][j] = dp[i-1][j]+1;
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    cout << dp[h-1][w-1] << el;
    return 0;
}