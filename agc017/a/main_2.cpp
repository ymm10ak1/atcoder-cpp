// A - Biscuits
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

ll dp[55][2];

int main(){
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    dp[0][0] = 1;
    rep(i,n){
        rep(j,2){
            dp[i+1][j] += dp[i][j];
            dp[i+1][(j+a[i])%2] += dp[i][j];
        }
    }
    cout << dp[n][p] << el;
    return 0;
}
