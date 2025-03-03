#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

struct UnionFind{
    vector<int> par, siz;

    UnionFind(int n){
        par.resize(n,-1);
        siz.resize(n,1);
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

    bool same(int x, int y){
        return root(x) == root(y);
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<int> a(m), b(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        if(!uf.same(a[i], b[i])) uf.unite(a[i], b[i]);
    }
    // 隣接リストgを使わずにunionfindのサイズを使うように変更
    vector<int> cnte(n), cntv(n);
    rep(i,n) cntv[uf.root(i)] = uf.siz[uf.root(i)];
    rep(i,m) cnte[uf.root(a[i])]++;
    ll ans = 0;
    rep(i,n) if(cntv[i] > 0) ans += (ll)cntv[i]*(cntv[i]-1)/2-cnte[i];
    cout << ans << el;
    return 0;
}
