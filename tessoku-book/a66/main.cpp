// A66 - Coonect Query
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

class UnionFind{
    public:
    int par[100005]; // 拡張店の親の番号
    int siz[100005]; // 拡張店の頂点数

    void init(int n){
        // はじめは各頂点はどの頂点とも結ばれてない
        rep(i,n) par[i] = -1;
        rep(i,n) siz[i] = 1;
    }

    // 頂点xの根を返す関数
    int root(int x){
        while(true){
            if(par[x] == -1) break;
            x = par[x];
        }
        return x;
    }

    // 頂点uとvを統合する関数
    void unite(int u, int v){
        int rootu = root(u);
        int rootv = root(v);
        // 同じ親を持つなら終了
        if(rootu == rootv) return;
        // u,vそれぞれの持つ頂点数でどっちを親にするか決める
        if(siz[rootu] < siz[rootv]){
            par[rootu] = rootv;
            siz[rootv] = siz[rootv]+siz[rootu];
        }else{
            par[rootv] = rootu;
            siz[rootu] = siz[rootu]+siz[rootv];
        }
    }

    // 頂点uとvが同じグループに属するか判定する関数
    bool same(int u, int v){
        int rootu = root(u);
        int rootv = root(v);
        return rootu == rootv;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    UnionFind uf;
    uf.init(n);
    rep(i,q){
        int t, u, v;
        cin >> t >> u >> v;
        --u; --v;
        if(t == 1){
            uf.unite(u, v);
        }else if(t == 2){
            if(uf.same(u, v)) cout << "Yes" << el;
            else cout << "No" << el;
        }
    }
    return 0;
}