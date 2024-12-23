// C
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
    ll n; cin >> n;
    ll ans = 0;
    for(ll i=1; i*i*i<=n; ++i){
        ll num = i*i*i;
        string s = to_string(num);
        int len = s.size();
        bool ok = true;
        rep(j,len/2){
            if(s[j] != s[len-1-j]) ok = false;
        }
        if(ok) ans = max(ans, num);
    }
    cout << ans << el;
    return 0;
}
