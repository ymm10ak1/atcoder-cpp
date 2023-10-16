// D - K項足し算
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<ll> b(n+1, 0);
    rep(i, n) cin >> a[i];
    rep(i, n) b[i+1] = b[i]+a[i];
    int out = n-k+1;
    rep(i, out){
        cout << b[i+k]-b[i] << el;
    }
    return 0;
}