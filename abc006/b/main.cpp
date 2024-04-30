// B -トリボナッチ数列
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

const int MOD = 10007;
int dp[1000005];

int main(){
    int n; cin >> n;
    dp[0] = 0, dp[1] = 0, dp[2] = 1;
    repi(i,3,n){
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%MOD;
    }
    cout << dp[n-1] << el;
    return 0;
}