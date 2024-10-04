// C - ±1 Operation 1
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

ll binarySearch(ll x, ll a, ll n, int d){
    ll l = -1, r = n;
    ll m = 0;
    ll ans = 2*LLINF;
    while(abs(r-l) > 1){
        m = (l+r)/2;
        ll v = a+m*d;
        if(d >= 0){
            if(x < v) r = m;
            else l = m;
        }else{
            if(x < v) l = m;
            else r = m;
        }
        ans = min(ans, abs(x-v));
    }
    return ans;
}

int main(){
    ll x, a, n;
    int d;
    cin >> x >> a >> d >> n;
    cout << binarySearch(x, a, n, d) << el;
    return 0;
}
