// D - パ研軍旗
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

// dp[i][j]: i列目の色をjにしたときの塗り替える回数
int dp[1005][3];

int main(){
    int n; cin >> n;
    vector<string> s(5);
    rep(i,5) cin >> s[i];
    rep(i,n)rep(j,3) dp[i][j] = INF;
    rep(i,n){
        rep(j,3){
            int sum = 0;
            rep(k,5){
                if(j==0 && s[k][i] != 'B') sum++;
                else if(j==1 && s[k][i] != 'W') sum++;
                else if(j==2 && s[k][i] != 'R') sum++;
            }
            if(i > 0){
                rep(k,3) if(j != k) dp[i][j] = min(dp[i][j], dp[i-1][k]+sum);
            }else{
                dp[i][j] = sum;
            }
        }
    }
    int ans = INF;
    rep(i,3) ans = min(ans, dp[n-1][i]);
    cout << ans << el;
    return 0;
}