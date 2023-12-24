// A20 - LCS
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
    string s, t;
    cin >> s >> t;
    // 動的計画法
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
    rep(i, s.size()+1){
        rep(j, t.size()+1){
            if(i>=1 && j>=1 && s[i-1]==t[j-1]) dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+1});
            else if(i>=1 && j>=1) dp[i][j] = max({dp[i-1][j], dp[i][j-1]});
        }
    }
    cout << dp[s.size()][t.size()] << el;
    return 0;
}