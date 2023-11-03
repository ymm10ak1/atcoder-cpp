// C - ORXOR 
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
using ull = unsigned long long;

int main(){
    int n;
    cin >> n;
    vector<ull> a(n);
    rep(i, n) cin >> a[i];
    ull ans = LINF;
    rep(bit, (1<<n-1)){
        bitset<30> kukan;
        ull a_or = a[0];
        bitset<30> or_bs(a[0]);
        rep(i, n-1){
            if(bit&(1<<i)){
                kukan ^= or_bs;
                or_bs = bitset<30>(a[i+1]);
            }else{
                or_bs |= bitset<30>(a[i+1]);
            }
        }
        kukan ^= or_bs;
        ans = min(ans, kukan.to_ullong());
    }
    cout << ans << el;
    return 0;
}