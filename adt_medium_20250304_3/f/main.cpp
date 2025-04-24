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
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    int ans = INF;
    rep(i,n){
        int idx = lower_bound(all(b), a[i])-b.begin();
        if(idx < m) ans = min(ans, abs(b[idx]-a[i]));
        if(idx-1 >= 0) ans = min(ans, abs(b[idx-1]-a[i]));
    }
    rep(i,m){
        int idx = lower_bound(all(a), b[i])-a.begin();
        if(idx < n) ans = min(ans, abs(a[idx]-b[i]));
        if(idx-1 >= 0) ans = min(ans, abs(a[idx-1]-b[i]));
    }
    cout << ans << el;
    return 0;
}
