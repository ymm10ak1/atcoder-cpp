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

struct UnionFind{
    vector<int> par, siz;

    UnionFind(int n){
        par.assign(n, -1);
        siz.assign(n, 0);
    }

    int root(int x){
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    void unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return;
        if(siz[rx] < siz[ry]){
            siz[ry] += siz[rx];
            par[rx] = ry;
        }else{
            siz[rx] += siz[ry];
            par[ry] = rx;
        }
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

};

int main(){
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    int ans = 0;
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        if(uf.same(u, v)) ans++;
        uf.unite(u, v);
    }
    cout << ans << el;
    return 0;
}
