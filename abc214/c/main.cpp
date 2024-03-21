// C - Distribution
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

ll dp[200010];

int main(){
    int n; cin >> n;
    vector<ll> s(n), t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];
    dp[0] = t[0];
    repi(i,1,2*n){
        dp[i%n] = min(dp[(i-1)%n]+s[(i-1)%n], t[i%n]);
    }
    rep(i,n) cout << dp[i] << el;
    return 0;
}