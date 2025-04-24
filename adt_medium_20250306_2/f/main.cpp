// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;
// }}}

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<int> ans(n);
    rep(i,n) ans[i] = i;
    sort(all(ans),[&](const int& i, const int& j){
        if((ll)(a[j]+b[j])*a[i] == (ll)(a[i]+b[i])*a[j]) return i < j;
        return (ll)(a[j]+b[j])*a[i] > (ll)(a[i]+b[i])*a[j];
    });
    rep(i,n) printf("%d%c", ans[i]+1, i==n-1?'\n':' ');
    return 0;
}
