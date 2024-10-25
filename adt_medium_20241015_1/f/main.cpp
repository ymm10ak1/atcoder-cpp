// F
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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll s = 0;
    rep(i,n) s += a[i];
    ll ave = s/n;
    int r = s%n;
    ll minus = 0, plus = 0;
    ll ans = 0;
    sort(rall(a));
    rep(i,n){
        ll d = r>0 ? ave+1 : ave;
        // plusになっている差分だけ求めればよい
        if(d-a[i] < 0) minus += d-a[i];
        else plus += d-a[i];
        r--;
    }
    ans = max(plus, -minus);
    cout << ans << el;
    return 0;
}
