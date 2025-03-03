#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    ll a, m, l, r;
    cin >> a >> m >> l >> r;

    auto f = [&](ll a, ll x){
        return (x-a)/m;
    };

    ll ans = 0;
    if(a < l){
        ans = f(a,r)-f(a,l-1);
    }else if(a > r){
        ans = f(-a,-l)-f(-a,-(r+1));
    }else{
        ans = abs(f(a,l))+abs(f(a,r))+1;
    }
    cout << ans << el;
    return 0;
}
