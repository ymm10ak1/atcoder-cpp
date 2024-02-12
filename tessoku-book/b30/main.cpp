// B30 - Combination 2
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

const int MOD = 1000000007;

ll power(ll a, ll b){
    ll p = a, res = 1;
    rep(i, 60){
        if((b>>i) & 1) res = (res*p)%MOD;
        p = (p*p)%MOD;
    }
    return res;
}

ll division(ll a, ll b){
    return (a*power(b, MOD-2))%MOD;
}

int main(){
    int h, w;
    cin >> h >> w;
    int n = h+w-2;
    ll a = 1;
    repi(i, 1, n+1) a = (a*i)%MOD;
    ll b = 1;
    repi(i, 1, w) b = (b*i)%MOD;
    repi(i, 1, n-w+2) b = (b*i)%MOD;
    cout << division(a, b) << el;
    return 0;
}