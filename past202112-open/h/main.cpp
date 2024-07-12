// H -最長非共通部分列
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

// dp[i][j]: Sのi文字目までとTのj文字目までで作ることのできる非共通部分列の長さ
int dp[5005][5005];

int main(){
    string s, t;
    cin >> s >> t;
    dp[0][0] = 0;
    repi(i,1,s.size()+1){
        repi(j,1,t.size()+1){
            if(s[i-1] != t[j-1]) dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+1});
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[(int)s.size()][(int)t.size()] << el;
    return 0;
}