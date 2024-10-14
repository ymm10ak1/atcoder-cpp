// D - Do use hexagon grid
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

const int dx[] = {-1,-1,0,0,1,1};
const int dy[] = {-1,0,-1,1,0,1};

class UnionFind{
public:
    vector<int> siz, par;
    
    UnionFind(int n){
        siz.resize(n,1);
        par.resize(n,-1);
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
    int n; cin >> n;
    UnionFind uf(n);
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            if(uf.same(i,j)) continue;
            rep(k,6){
                int nx = x[i]+dx[k], ny = y[i]+dy[k];
                if(nx==x[j] && ny==y[j]) uf.unite(i,j);
            }
        }
    }
    set<int> st;
    rep(i,n) st.insert(uf.root(i));
    cout << st.size() << el;
    return 0;
}
