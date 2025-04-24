// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;
// }}}

int main(){
    int k; string a, b;
    cin >> k >> a >> b;

    auto f = [&](string a){
        reverse(all(a));
        int kd = 1, res = 0;
        rep(i,a.size()){
            res += (a[i]-'0')*kd;
            kd *= k;
        }
        return res;
    };

    ll ans = (ll)f(a)*f(b);
    cout << ans << el;
    return 0;
}
