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
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n,vector<ll>(n,-LLINF));
    rep(i,m){
        int u, v; ll w;
        cin >> u >> v >> w;
        u--; v--;
        g[u][v] = g[v][u] = w;
    }
    vector<int> a(n);
    rep(i,n) a[i] = i;
    ll ans = 2*LLINF;
    do{
        if(a[0] != 0) continue;
        bool ok = true;
        ll x_or = 0;
        rep(i,n-1){
            if(g[a[i]][a[i+1]] == -LLINF){
                ok = false; break;
            }
            x_or ^= g[a[i]][a[i+1]];
            if(a[i+1] == n-1) break;
        }
        if(ok) ans = min(ans, x_or);
    }while(next_permutation(all(a)));
    cout << ans << el;
    return 0;
}
