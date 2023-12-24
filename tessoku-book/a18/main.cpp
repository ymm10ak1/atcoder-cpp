// A18 - Subset Sum
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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<bool>> dp(n+1, vector<bool>(s+1));
    // 動的計画法(i=0)
    dp[0][0] = true;
    repi(i, 1, s+1) dp[0][i] = false;
    // 動的計画法(i>=1)
    repi(i, 1, n+1){
        rep(j, s+1){
            if(j < a[i-1]){
                if(dp[i-1][j] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
            if(j >= a[i-1]){
                if(dp[i-1][j]==true || dp[i-1][j-a[i-1]]==true) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }
    if(dp[n][s] == true) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}