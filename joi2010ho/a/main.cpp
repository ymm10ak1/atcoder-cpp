// A - 旅人
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n-1);
    rep(i, n-1) cin >> a[i];
    vector<int> b(n, 0);
    rep(i, n-1) b[i+1] = b[i]+a[i];
    int old = 0, cur = 0;
    int ans = 0;
    rep(i, m){
        cin >> cur;
        cur = cur+old;
        if(cur < 0) cur = 0;
        else if(cur > 100000) cur = 100000;
        int r_idx = max(cur, old);
        int l_idx = min(cur, old);
        ans += (b[r_idx]-b[l_idx]);
        ans %= 100000;
        old = cur;
    }
    ans %= 100000;
    cout << ans << el;
    return 0;
}