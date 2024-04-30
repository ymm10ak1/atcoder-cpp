// D - Flip Cards
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

const int MOD = 998244353;
int dp[200005][2];

int main(){
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    repi(i,1,n+1) cin >> a[i] >> b[i];
    dp[1][0] = dp[1][1] = 1;
    repi(i,1,n){
        // i番目のカードの表と裏について、それぞれ隣のカード(i+1)の表と裏との数が異なるか
        if(a[i] != a[i+1]) dp[i+1][0] = (dp[i+1][0]+dp[i][0])%MOD;
        if(a[i] != b[i+1]) dp[i+1][1] = (dp[i+1][1]+dp[i][0])%MOD;
        if(b[i] != a[i+1]) dp[i+1][0] = (dp[i+1][0]+dp[i][1])%MOD;
        if(b[i] != b[i+1]) dp[i+1][1] = (dp[i+1][1]+dp[i][1])%MOD;
    }
    int ans = (dp[n][0]+dp[n][1])%MOD;
    cout << ans << el;
    return 0;
}