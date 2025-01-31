// 
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
    ll d;
    cin >> n >> m >> d;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    set<ll> stb;
    rep(i,m) stb.insert(-b[i]);
    sort(all(a));
    ll ans = -1;
    rep(i,n){
        ll key = -(a[i]+d);
        auto it1 = stb.lower_bound(key);
        ll v = -(a[i]-d);
        while(it1 != stb.end()){
            if(*it1 > v) break;
            ans = max(ans,-(*it1)+a[i]);
            break;
        }
    }
    cout << ans << el;
    return 0;
}
