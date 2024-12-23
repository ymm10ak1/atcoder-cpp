// C - Approximate Equalization 2
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

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll s = 0;
    rep(i,n) s += a[i];
    ll ave = s/n;
    int r = s%n;
    sort(rall(a));
    ll ans = 0;
    rep(i,n){
        if(r > 0){
            ans += abs(a[i]-ave-1);
            r--;
        }else{
            ans += abs(a[i]-ave);
        }
    }
    cout << ans/2 << el;
    return 0;
}
