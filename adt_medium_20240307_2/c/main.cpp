// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<bool>> g(n,vector<bool>(n,false));
    rep(i,m){
        int u,v; cin >> u >> v;
        --u; --v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    int ans = 0;
    rep(i,n-2){
        repi(j,i+1,n-1){
            repi(k,j+1,n){
                if(g[i][j] && g[j][i] && g[j][k] && g[k][j] && g[k][i] && g[i][k]) ++ans;
            }
        }
    }
    cout << ans << el;
    return 0;
}