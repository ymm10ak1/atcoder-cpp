// H - Grid 1
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

const int MOD = 1000000007;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    vector<vector<ll>> dp(h,vector<ll>(w,0));
    dp[0][0] = 1LL;
    rep(i,h){
        rep(j,w){
            if(a[i][j] == '#'){
                dp[i][j] = 0;
            }else{
                if(i>0 && j>0) dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
                else if(i>0 && j==0) dp[i][j] = dp[i-1][j];
                else if(j>0 && i==0) dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout << dp[h-1][w-1] << el;
    return 0;
}