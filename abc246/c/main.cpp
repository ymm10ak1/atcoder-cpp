// C - Coupon
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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(rall(a));
    rep(i,n){
        int d = a[i]/x;
        a[i] = a[i]-min(d,k)*x;
        k -= min(d,k);
        if(k <= 0) break;
    }
    sort(rall(a));
    rep(i,min(k,n)) a[i] = 0;
    ll ans = 0;
    rep(i,n) ans += a[i];
    cout << ans << el;
    return 0;
}
