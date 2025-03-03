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
    ll d; cin >> d;
    const ll N = 2*1e6+1;
    ll ans = LLINF;
    for(ll i=1; i<N; ++i){
        ll x = i*i;
        ll l = 0, r = N;
        while(abs(r-l) > 1){
            ll mid = (r+l)/2;
            if(-(mid*mid) <= x-d) r = mid;
            else l = mid;
        }
        ans = min(ans,abs(x+r*r-d));
        ans = min(ans,abs(x+l*l-d));
    }
    cout << ans << el;
    return 0;
}
