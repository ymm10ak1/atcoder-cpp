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
    map<ll,ll> mp;
    mp[1] = 0;
    mp[2] = 2;
    auto f = [&](auto f, ll x){
        if(mp.count(x)) return mp[x];
        return mp[x] = x+f(f,x/2)+f(f,(x+1)/2);
    };
    ll ans = f(f,n);
    cout << ans << el;
    return 0;
}
