// C - chokudai
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
const string S = "chokudai";

int main(){
    string s; cin >> s;
    vector<vector<int>> dp(8,vector<int>((int)s.size(),0));
    // 初期化
    dp[0][0] = s[0]=='c'?1:0;
    rep(i,8){
        rep(j,s.size()){
            if(j > 0){
                if(s[j]==S[i]){
                    if(i == 0) dp[i][j] = (dp[i][j-1]+1)%MOD;
                    else dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    cout << dp[7][s.size()-1] << el;
    return 0;
}