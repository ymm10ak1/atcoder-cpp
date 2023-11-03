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

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 1<<30;
    rep(bit, (1<<n-1)){
        int x_or = 0;
        int a_or = a[0];
        rep(i, n-1){
            if(bit&(1<<i)){
                x_or ^= a_or;
                a_or = a[i+1];
            }else{
                a_or |= a[i+1];
            }
        }
        x_or ^= a_or;
        ans = min(ans, x_or);
    }
    cout << ans << el;
    return 0;
}