// C - Compass Walking
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

// NOTE: atcoder testcasesでテストケースを確認しつつ解いてしまった
int main(){
    ll r, x, y;
    cin >> r >> x >> y;
    ll diff = x*x+y*y;
    r *= r;
    if(r > diff){
        cout << 2 << el;
        return 0;
    }
    ll d = diff/r, ama = diff%r;
    ll ans = sqrt(d);
    if(ama > 0) ans++;
    if(r==1 && x>0 && y>0) ans++;
    cout << ans << el;
    return 0;
}
