// 082 - Counting Numbers（★3）
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

ll pow2(ll a, ll b){
    ll ret = 1;
    while(b > 0){
        if(b & 1) ret = ret*a%M;
        a = a*a%M;
        b >>= 1;
    }
    return ret;
}

ll createSum(ll n, ll _a){
    ll v = 1, a = n;
    int cnt = 0;
    ll sums[20] = {0};
    while(n > 0){
        v *= 10;
        n /= 10;
        ll sum = 1;
        if(n == 0) sum = (((a%M)*((a+1)%M))%M*(_a%M))%M;
        else sum = (((v%M)*((v-1)%M))%M*(_a%M))%M;
        sums[++cnt] = sum;
    }
    ll ret = 1;
    repi(i,1,cnt+1){
        ll d = (sums[i]%M-sums[i-1]%M)%M;
        if(d < 0) d += M;
        ret = (ret%M+(i*d%M))%M;
    }
    return ret;
}

int main(){
    ll l, r;
    cin >> l >> r;
    ll _a = pow2(2LL, M-2);
    ll sumr = createSum(r, _a);
    ll suml = createSum(l-1, _a);
    ll ans = (sumr-suml)%M;
    if(ans < 0) ans += M;
    cout << ans << el;
    return 0;
}
