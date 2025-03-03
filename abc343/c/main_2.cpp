#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    ll n; cin >> n;
    ll ans = 0;
    for(ll x=0; x*x*x<=n; ++x){
        string s = to_string(x*x*x);
        int n = s.size();
        bool ok = true;
        rep(i,n/2) if(s[i] != s[n-i-1]) ok = false;
        if(ok) ans = max(ans, x*x*x);
    }
    cout << ans << el;
    return 0;
}
