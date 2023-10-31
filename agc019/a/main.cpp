// A - Ice Tea Store 
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
    int q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    ll ans = 0;
    if(n > 1){
        // q, h, sを2Lの価格に変更し、一番小さいものを使用する
        ans = 1LL*(n/2)*min(q*8, min(h*4, min(s*2, d)));
    }
    if(n%2 == 1){
        ans += min(q*4, min(h*2, s));
    }
    cout << ans << el;
    return 0;
}