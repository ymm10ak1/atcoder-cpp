// C - Bridge
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

class UnionFind{
public:
    vector<int> par, siz;
    
    UnionFind(int n){
        par.resize(n, -1);
        siz.resize(n, 1);
    }
    
    int root(int x){
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }
    
    void unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return;
        if(siz[rx] < siz[ry]){
            par[rx] = ry;
            siz[ry] += siz[rx];
        }else{
            par[ry] = rx;
            siz[rx] += siz[ry];
        }
    }
    
    bool issame(int x, int y){
        return root(x) == root(y);
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        --a[i]; --b[i];
    }
    int ans = 0;
    rep(i,m){
        UnionFind uf(n);
        rep(j,m){
            if(i == j) continue;
            if(!uf.issame(a[j], b[j])) uf.unite(a[j], b[j]);
        }
        // NOTE: 橋を調べる処理について、どれか1つ頂点を選んでその親のサイズがn未満なら非連結と判定する方法もある
        int u = uf.root(0);
        bool ng = false;
        repi(j,1,n) if(u != uf.root(j)) ng = true;
        if(ng) ans++;
    }
    cout << ans << el;
    return 0;
}
