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
    vector<int> a;
    rep(i,n){
        int ai; cin >> ai;
        if(i == 0) continue;
        a.push_back(ai);
    }
    int q; cin >> q;
    vector<int> l(q), r(q);
    rep(i,q) cin >> l[i] >> r[i];
    vector<int> b;
    for(int i=0; i<n-1; i+=2) b.push_back(a[i+1]-a[i]);
    vector<ll> s(b.size()+1);
    rep(i,b.size()) s[i+1] = s[i]+b[i];
    rep(i,q){
        int li = lower_bound(all(a),l[i])-a.begin();
        ll mi = 0;
        if(li%2) mi += l[i]-a[li-1];
        int ri = lower_bound(all(a),r[i])-a.begin();
        if(ri%2) mi += a[ri]-r[i];
        else mi += a[ri+1]-a[ri];
        ll ans = s[ri/2+1]-s[li/2]-mi;
        cout << ans << el;
    }
    return 0;
}
