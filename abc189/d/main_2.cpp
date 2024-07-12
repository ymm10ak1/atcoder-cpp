// D - Logical Expression
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

ll dp[65][2];

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    dp[0][0] = dp[0][1] = 1;
    rep(i,n){
        rep(j,2){
            if(s[i] == "AND"){
                dp[i+1][j & 0] += dp[i][j];
                dp[i+1][j & 1] += dp[i][j];
            }else if(s[i] == "OR"){
                dp[i+1][j | 0] += dp[i][j];
                dp[i+1][j | 1] += dp[i][j];
            }
        }
    }
    cout << dp[n][1] << el;
    return 0;
}