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

const int M = 998244353;

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> x10;
    rep(i,n){
        int ai = a[i]; ll x = 1;
        while(ai){
            ai /= 10;
            x *= 10;
        }
        x10.push_back(x);
    }
    vector<ll> s(n+1);
    rep(i,n) s[i+1] = (s[i]+a[i])%M;
    ll ans = 0;
    repi(i,1,n) ans = (ans+(s[i]*(x10[i]%M))%M)%M;
    repi(i,1,n) ans = (ans+(i*a[i])%M)%M;
    cout << ans << el;
    return 0;
}
