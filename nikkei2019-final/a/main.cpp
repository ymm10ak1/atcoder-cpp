// A - Abundant Resources
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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> b(n+1);
    rep(i, n) cin >> a[i];
    rep(i, n) b[i+1] = b[i]+a[i];
    vector<ll> ans;
    repi(i, 1, n+1){
        ll v = 0;
        for(int j=0; j+i<=n; ++j){
            v = max(v, b[j+i]-b[j]);
        }
        ans.push_back(v);
    }
    for(auto v : ans) cout << v << el;
    return 0;
}