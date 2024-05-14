// B67 - Max MST
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
    int par[100005];
    int siz[100005];

    void init(int n){
        rep(i,n+1){
            par[i] = -1;
            siz[i] = 1;
        }
    }

    int root(int x){
        while(true){
            if(par[x] == -1) break;
            x = par[x];
        }
        return x;
    }

    void unite(int u, int v){
        int rootu = root(u);
        int rootv = root(v);
        if(rootu == rootv) return;
        if(siz[rootu] < siz[rootv]){
            par[rootu] = rootv;
            siz[rootv] += siz[rootu];
        }else{
            par[rootv] = rootu;
            siz[rootu] += siz[rootv];
        }
    }

    bool same(int u, int v){
        return (root(u) == root(v));
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<pair<int, int>> edge(m);
    rep(i,m){
        cin >> a[i] >> b[i] >> edge[i].first;
        edge[i].second = i;
    }
    sort(rall(edge));
    UnionFind uf;
    uf.init(n);
    int ans = 0;
    rep(i,m){
        int idx = edge[i].second;
        if(!uf.same(a[idx], b[idx])){
            ans += edge[i].first;
            uf.unite(a[idx], b[idx]);
        }
    }
    cout << ans << el;
    return 0;
}