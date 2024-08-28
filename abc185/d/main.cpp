// D - Stamp
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
    vector<ll> a(m);
    rep(i,m) cin >> a[i];
    a.push_back(0);
    a.push_back((ll)n+1);
    sort(all(a));
    ll minv = LLINF;
    rep(i,a.size()-1) if(a[i+1]-a[i]-1 > 0) minv = min(minv, a[i+1]-a[i]-1);
    if(minv == LLINF){
        cout << 0 << el;
        return 0;
    }
    ll ans = 0;
    rep(i,a.size()-1){
        if(a[i+1]-a[i]-1 > 0){
            ll x = a[i+1]-a[i]-1;
            ll v = (x+minv-1)/minv;
            ans += v;
        }
    }
    cout << ans << el;
    return 0;
}
