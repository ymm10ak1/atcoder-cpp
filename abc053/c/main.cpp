// C -Yet Another Die Game
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
    ll x; cin >> x;
    ll ans = x/11==0 ? 0 : x/11*2;
    ll r = x%11;
    if(r>0 && r<=6) ans += 1;
    else if(r>6 && r<11) ans += 2;
    cout << ans << el;
    return 0;
}
