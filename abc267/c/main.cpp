// C - Index x A(Continuous ver.)
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

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> s(n+1, 0);
    rep(i,n) s[i+1] = s[i] + a[i];
    ll sum = 0;
    rep(i,m) sum += s[i];
    ll ans = -LLINF;
    repi(i,m,n+1){
        ans = max(ans, m*s[i]-sum);
        sum -= s[i-m];
        sum += s[i];
    }
    cout << ans << el;
    return 0;
}
