// A - Comrime Pair
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

// NOTE: ほぼ解説ACみたいなもの
int main(){
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    rep(i,2000){
        rep(j,2000){
            if(l+i<r-j && gcd(r-j, l+i)==1) ans = max(ans, r-j-(l+i));
        }
    }
    cout << ans << el;
    return 0;
}
