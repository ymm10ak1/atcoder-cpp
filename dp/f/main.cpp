// F - LCS
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
    string s, t; cin >> s >> t;
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
    dp[0][0] = 0;
    repi(i,1,s.size()+1){
        repi(j,1,t.size()+1){
            if(s[i-1] == t[j-1]) dp[i][j] = max({dp[i-1][j-1]+1, dp[i-1][j], dp[i][j-1]});
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // dpを使って共通部分文字列を復元すれば良いみたい
    string ans = "";
    int l = s.size(), r = t.size();
    while(true){
        if(l==0 || r==0) break;
        // 左上、左、上の値がすべてdp[i][j]より低いなら文字列に追加
        if(dp[l-1][r]<dp[l][r] && dp[l][r-1]<dp[l][r] && dp[l-1][r-1]<dp[l][r]){
            ans += s[l-1];
            l--; r--;
        }else if(dp[l-1][r-1] == dp[l][r]){
            l--; r--;
        }else if(dp[l-1][r] == dp[l][r]){
            l--;
        }else if(dp[l][r-1] == dp[l][r]){
            r--;
        }
    }
    reverse(all(ans));
    cout << ans << el;
    return 0;
}