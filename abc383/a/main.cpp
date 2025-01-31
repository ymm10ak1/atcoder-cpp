// 
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
    vector<int> t(n), v(n);
    rep(i,n) cin >> t[i] >> v[i];
    int ans = v[0];
    repi(i,1,n){
        ans -= (t[i]-t[i-1]);
        if(ans < 0) ans = 0;
        ans += v[i];
    }
    cout << ans << el;
    return 0;
}
