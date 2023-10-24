// C - Walking Takahashi
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    ll div = x/d;
    ll r = x%d;
    if(k >= div){
        k -= div;
        x -= (div*d);
        if(k%2 == 0){
            cout << x << el;
        }else{
            ll res = min(abs(x-d), x+d);
            cout << res << el;
        }
    }else{
        x -= (k*d);
        cout << x << el;
    }
    return 0;
}