// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;
// }}}

int main(){
    int n; ll x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    sort(rall(a));
    int ans = INF;
    rep(i,n){
        x -= a[i];
        if(x < 0){
            ans = min(ans, i+1);
            break;
        }
    }
    sort(rall(b));
    rep(i,n){
        y -= b[i];
        if(y < 0){
            ans = min(ans, i+1);
            break;
        }
    }
    if(ans == INF) ans = n;
    cout << ans << el;
    return 0;
}
