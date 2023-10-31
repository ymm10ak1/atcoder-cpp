// Greedy Takahashi
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
    ll a, b, k;
    cin >> a >> b >> k;
    if(a < k){
        ll b_res = b-(k-a) < 0 ? 0 : b-(k-a);
        cout << 0 << " " << b_res << el;
    }else{
        cout << a-k << " " << b << el;
    }
    return 0;
}