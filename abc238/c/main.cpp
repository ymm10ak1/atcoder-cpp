// C - digitnum
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

const int M = 998244353;

ll powmod(ll n, ll k){
    ll res = 1;
    while(k){
        if(k & 1) res = (res*n)%M;
        n = (n*n)%M;
        k >>= 1;
    }
    return res;
}

int main(){
    ll n; cin >> n;
    ll nn = n;
    vector<ll> x10;
    ll x = 1;
    while(nn){
        x10.push_back(x);
        nn /= 10;
        x *= 10;
    }
    ll ans = 0;
    ll m2 = powmod(2,M-2);
    while(!x10.empty()){
        ll d = x10.back();
        ll n2 = n-(d-1);
        ans = (ans+(((n2%M)*((n2+1)%M))%M*m2)%M)%M;
        n = d-1;
        x10.pop_back();
    }
    cout << ans << el;
    return 0;
}
