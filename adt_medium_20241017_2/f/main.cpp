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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    ll ng = min(a[0], b[0]), ok = max(a[n-1], b[m-1]);
    ok++; ng--;
    ll ans = LLINF;
    while(abs(ok-ng)>1){
        ll x = (ok+ng)/2;
        int cnta = 0, cntb = 0;;
        rep(i,n) if(x >= a[i]) cnta++;
        rep(i,m) if(x <= b[i]) cntb++;
        if(cnta >= cntb){
            ok = x;
            ans = min(ans, x);
        }else{
            ng = x;
        }
    }
    // NOTE: ansとか用意する必要はなくokだけを出力すればよさそう？
    if(ans == LLINF) ans = ok;
    cout << ans << el;
    return 0;
}
