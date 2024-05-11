// D - Redistribution
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

int dp[2005];

int main(){
    int s; cin >> s;
    dp[0] = 1;
    repi(i,3,s+1){
        rrepi(j,i-2,0) dp[i] = (dp[i]+dp[j])%MOD;
    }
    cout << dp[s] << el;
    return 0;
}