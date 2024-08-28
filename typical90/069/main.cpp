// 069 - Colorful Blocks 2（★3）
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

constexpr int M = 1000000007;

ll powMod(ll a, ll b){
    ll ret = 1;
    while(b > 0){
        if(b & 1) ret = ret*a%M;
        a = a*a%M;
        b >>= 1;
    }
    return ret;
}

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if(n == 1) ans = k%M;
    else ans = (((k%M)*((k-1)%M))%M*(powMod(k-2, n-2)%M))%M;
    cout << ans << el;
    return 0;
}
