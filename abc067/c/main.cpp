// C - Splitting Pile
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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> b(n+1, 0);
    rep(i,n) b[i+1] = b[i]+a[i];
    ll ans = LLINF;
    repi(i,1,n) ans = min(ans, abs(b[n]-b[i]-b[i]));
    cout << ans << el;
    return 0;
}
