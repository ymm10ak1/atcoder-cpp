// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;
// }}}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> b(n), w(m);
    rep(i,n) cin >> b[i];
    rep(i,m) cin >> w[i];
    sort(rall(b));
    sort(rall(w));
    vector<ll> sb(n+1), sw(m+1);
    rep(i,n) sb[i+1] = sb[i]+b[i];
    rep(i,m) sw[i+1] = sw[i]+w[i];
    ll ans = 0;
    int r = 0, len = min(n, m);
    rep(l,len+1){
        ll tmp = sb[r]+sw[l];
        while(r+1<n+1 && tmp <= sb[r+1]+sw[l]){
            tmp = sb[r+1]+sw[l];
            r++;
        }
        ans = max(ans, tmp);
        if(l == r) r++;
    }
    cout << ans << el;
    return 0;
}
