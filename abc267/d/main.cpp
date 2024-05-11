// D - Index × A(Not Continuous ver.)
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

ll dp[2005][2005];

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,2005) rep(j,2005) dp[i][j] = -LLINF;
    dp[0][0] = 0;
    rep(i,n){
        rep(j,m+1){
            if(dp[i][j] != -LLINF){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                // Ai-1の前の項から足された値とAiの今の項で最大値をとる
                if(j+1 <= m) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+(a[i]*(j+1)));
            }
        }
    }
    cout << dp[n][m] << el;
    return 0;
}