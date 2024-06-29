// C - Anti-Division
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

ll gcd(ll x, ll y){
    if(y == 0) return x;
    else return gcd(y, x%y);
}

ll lcm(ll x, ll y){
    return x / gcd(x, y) * y;
}

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll r1 = b/c-(a-1)/c;
    ll r2 = b/d-(a-1)/d;
    ll lc = lcm(max(c,d), min(c,d));
    ll r3 = b/lc-(a-1)/lc;
    ll ans = (b-a+1)-(r1+r2-r3);
    cout << ans << el;
    return 0;
}