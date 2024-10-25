// G
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

const int M = 998244353;

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    int maxn = 0;
    rep(i,n) maxn = max({maxn, a[i], b[i]});
    vector<vector<int>> dp(n+1,vector<int>(maxn+1));
    dp[0][0] = 1;
    repi(i,1,n+1){
        vector<int> s = dp[i-1];
        rep(j,s.size()-1) s[j+1] = (s[j+1]+s[j])%M;
        repi(j,a[i-1],b[i-1]+1) dp[i][j] = s[j];
    }
    int ans = 0;
    rep(i,maxn+1) ans = (ans+dp[n][i])%M;
    cout << ans << el;
    return 0;
}
