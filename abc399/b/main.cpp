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
const int INF = (1<<30);
const ll LLINF = (1LL<<60);
// }}}

int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    vector<P> q(n);
    rep(i,n){ q[i].first =  p[i], q[i].second = i; } 
    sort(rall(q));
    vector<int> ans(n);
    int r = 1, rr = 1, top = q[0].first;
    rep(i,n){
        if(top != q[i].first){
            r = rr;
            top = q[i].first;
        }
        rr++;
        ans[q[i].second] = r;
    }
    rep(i,n) cout << ans[i] << el;
    return 0;
}
