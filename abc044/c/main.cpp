// C - 高橋くんとカード
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
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    int sum = 0;
    rep(i,n){
        cin >> x[i];
        sum += x[i];
    }
    // 解説見るとdp[i][j][k]:N個の整数のうちの最初のi個から、j個選ぶ場合について、総和をkにするものが何個あるか
    // 平均値がAは個数がj個のとき、総和がAjとなるので、k<=Aj
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(n+1,vector<ll>(sum+1,0LL)));
    rep(i,n+1) dp[i][0][0] = 1;
    repi(i,1,n+1){
        repi(j,1,i+1){
            rep(k,sum+1){
                if(k-x[i-1]>=0){
                    if(dp[i-1][j-1][k-x[i-1]] >= 1) dp[i][j][k] = dp[i-1][j-1][k-x[i-1]]+dp[i-1][j][k];
                    else dp[i][j][k] = dp[i-1][j][k];
                }else{
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }
    ll ans = 0;
    repi(i,1,n+1){
        rep(j,sum+1){
            int ave = j/i, r = j%i;
            if(dp[n][i][j]>=1 && ave==a && r==0) ans += dp[n][i][j];
        }
    }
    cout << ans << el;
    return 0;
}