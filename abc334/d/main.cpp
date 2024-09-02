// D - Reindeer and Sleigh
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
    int n, q;
    cin >> n >> q;
    vector<int> r(n);
    rep(i,n) cin >> r[i];
    sort(all(r));
    vector<ll> s(n+1);
    rep(i,n) s[i+1] = s[i]+r[i];
    rep(i,q){
        ll x; cin >> x;
        int idx = upper_bound(all(s), x)-s.begin();
        int ans = idx-1;
        cout << ans << el;
    }
    return 0;
}
