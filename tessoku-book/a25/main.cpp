// A25 - Number of Routes
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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<ll>> dp(h, vector<ll>(w));
    dp[0][0] = 0;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '.'){
                if(i>=1 && j>=1){
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }else if(i>=1){
                    if(i==1) dp[i][j] = dp[i-1][j]+1;
                    else dp[i][j] = dp[i-1][j];
                }else if(j>=1){
                    if(j==1) dp[i][j] = dp[i][j-1]+1;
                    else dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    cout << dp[h-1][w-1] << el;
    return 0;
}