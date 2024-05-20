// A - Irreversible operation
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

int dp[200005];

int main(){
    string s; cin >> s;
    dp[0] = s[0]=='B'?1:0;
    ll ans = 0;
    repi(i,1,s.size()){
        if(s[i] == 'W'){
            dp[i] = dp[i-1];
            ans += dp[i];
        }else{
            dp[i] = dp[i-1]+1;
        }
    }
    cout << ans << el;
    return 0;
}