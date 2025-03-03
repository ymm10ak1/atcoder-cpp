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

int main(){
    int n; cin >> n;
    vector<int> l(n), r(n);
    rep(i,n) cin >> l[i] >> r[i];
    ll ans = (ll)n*(n-1)/2;
    sort(all(l)); sort(all(r));
    rep(i,n){
        int idx = upper_bound(all(l), r[i])-l.begin();
        ans -= (n-idx);
    }
    cout << ans << el;
    return 0;
}
