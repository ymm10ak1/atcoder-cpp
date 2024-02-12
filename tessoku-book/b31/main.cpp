// B31 - Divisors Hard
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    ll n;
    cin >> n;
    ll p = n/3;
    ll q = n/5;
    ll r = n/7;
    ll pq = n/15;
    ll qr = n/35;
    ll pr = n/21;
    ll pqr = n/(3*5*7);
    ll ans = p+q+r-pq-qr-pr+pqr;
    cout << ans << el;
    return 0;
}