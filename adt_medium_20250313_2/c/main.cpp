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
const int INF = 2e9;
const ll LLINF = 2e18;
// }}}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n,vector<bool>(n));
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u][v] = g[v][u] = true;
    }
    int ans = 0;
    rep(a,n-2){
        repi(b,a+1,n-1){
            repi(c,b+1,n){
                if(g[a][b] && g[b][c] && g[c][a]) ans++;
            }
        }
    }
    cout << ans << el;
    return 0;
}
