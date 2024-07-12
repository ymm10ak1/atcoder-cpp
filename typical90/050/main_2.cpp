// 050 - Stair Jump（★3）
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

constexpr int M = 1000000007;
int dp[100005];

int main(){
    int n, l;
    cin >> n >> l;
    dp[0] = 1;
    repi(i,1,n+1){
        if(i-1 >= 0) dp[i] = (dp[i]+dp[i-1])%M;
        if(i-l >= 0) dp[i] = (dp[i]+dp[i-l])%M;
    }
    cout << dp[n] << el;
    return 0;
}