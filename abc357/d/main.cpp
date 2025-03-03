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

ll pow2(ll x, ll n){
    ll p = x, res = 1;
    while(n){
        if(n & 1) res = (res*p)%M;
        p = (p*p)%M;
        n >>= 1;
    }
    return res;
}

// NOTE: ヒントありで解いた
int main(){
    ll n; cin >> n;
    ll m = n, x = 1;
    while(m){ m /= 10; x *= 10; }
    ll rn = pow2(x%M,n);
    ll s = ((n%M*(rn-1)%M)%M*pow2((x-1)%M,M-2))%M;
    cout << s << el;
    return 0;
}
