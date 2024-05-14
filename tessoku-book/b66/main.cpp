// B66 - Typhoon
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

    // 頂点の親を探す関数
    int root(int x){
        while(true){
            if(par[x] == -1) return x;
            x = par[x];
        }
    }

    // 頂点uと頂点vを統合する関数
    void unite(int u, int v){
        int rootu = root(u);
        int rootv = root(v);
        // 同じ親ならば終了
        if(rootu == rootv) return;
        if(siz[rootu] < siz[rootv]){
            par[rootu] = rootv;
            siz[rootv] += siz[rootu];
        }else{
            par[rootv] = rootu;
            siz[rootu] += siz[rootv];
        }
    }

    // 頂点uと頂点vが同じグループに属しているか
    bool same(int u, int v){
        return (root(u) == root(v));
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i,m) cin >> a[i] >> b[i];
    int q; cin >> q;
    vector<vector<int>> Q(q);
    set<int> st;
    rep(i,q){
        int t; cin >> t;
        Q[i].push_back(t);
        if(t == 1){
            int x; cin >> x;
            Q[i].push_back(x);
            st.insert(x);
        }else if(t == 2){
            int u, v;
            cin >> u >> v;
            Q[i].push_back(u);
            Q[i].push_back(v);
        }
    }
    // UnionFind
    UnionFind uf;
    uf.init(n);
    // クエリ1にない辺を先に統合しておく
    rep(i,m){
        if(st.find(i+1) == st.end()) uf.unite(a[i], b[i]);
    }
    // クエリを逆から処理していく
    vector<string> ans;
    rrepi(i,q,0){
        // クエリ1のとき辺の削除ではなく追加する
        if(Q[i][0] == 1){
            int x = Q[i][1]; --x;
            uf.unite(a[x], b[x]);
        }else if(Q[i][0] == 2){
            int u = Q[i][1];
            int v = Q[i][2];
            if(uf.same(u, v)) ans.push_back("Yes");
            else ans.push_back("No");
        }
    }
    rrepi(i,(int)ans.size(),0) cout << ans[i] << el;
    return 0;
}