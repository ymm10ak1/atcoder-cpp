// スプリンクラー
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        g[u-1].push_back(v);
        g[v-1].push_back(u);
    }
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    rep(i, q){
        int s;
        cin >> s;
        if(s == 1){
            int x;
            cin >> x;
            x--;
            int cur_c = c[x];
            printf("%d\n", cur_c);
            // 隣接する頂点の色を塗り替える
            rep(j, g[x].size()) c[g[x][j]-1] = cur_c;
        }else{
            int x, y;
            cin >> x >> y;
            x--;
            printf("%d\n", c[x]);
            c[x] = y;
        }
    }
    return 0;
}