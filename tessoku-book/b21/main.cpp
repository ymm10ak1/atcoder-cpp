// B21 - Longest Subpalindrome
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
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    // NOTE: 区間dpについてまだよくわかっていない
    repi(LEN, 1, n+1){
        repi(l, 1, n-LEN+2){
            int r = l+LEN-1;
            if(s[l-1] == s[r-1]){
                if(r-l>1) dp[l][r] = max({dp[l+1][r-1]+2, dp[l+1][r], dp[l][r-1]});
                else dp[l][r] = dp[l][r-1]+1;
            }else{
                dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            }
        }
    }
    cout << dp[1][n] << el;
    return 0;
}