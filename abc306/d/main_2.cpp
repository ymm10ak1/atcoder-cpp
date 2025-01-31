// 
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

// dp[i][j]: i番目までの料理を食べてお腹の状態がjのときの最大値
ll dp[300005][2];

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    repi(i,1,n+1){
        if(x[i-1] == 1){
            dp[i][1] = max({dp[i-1][1], dp[i-1][0]+y[i-1]});
            dp[i][0] = max(dp[i][0], dp[i-1][0]);
        }else{
            dp[i][0] = max({dp[i-1][0], dp[i-1][1]+y[i-1], dp[i-1][0]+y[i-1]});
            dp[i][1] = max(dp[i][1], dp[i-1][1]);
        }
    }
    ll ans = max(dp[n][0], dp[n][1]);
    cout << ans << el;
    return 0;
}
