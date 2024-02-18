// 
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

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<int> s(n-1), t(n-1);
    rep(i,n-1) cin >> s[i] >> t[i];
    ll ans = a[n-1];
    rep(i,n-1){
        ll r = a[i]/s[i]*t[i];
        a[i+1] += r;
    }
    ans = max(ans, a[n-1]);
    cout << ans << el;
    return 0;
}