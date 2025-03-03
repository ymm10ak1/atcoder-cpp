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
    int n; ll m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    rep(i,n) sum += a[i]; 
    if(sum <= m){
        cout << "infinite" << el;
        return 0;
    }
    sort(all(a));
    ll ok = -1, ng = LLINF;
    while(abs(ok-ng) > 1){
        ll mid = (ok+ng)/2;
        ll s = 0;
        rep(i,n) s += min((ll)a[i],mid);
        if(s <= m) ok = mid;
        else ng = mid;
    }
    cout << ok << el;
    return 0;
}
