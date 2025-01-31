#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

const int dx[] = {-1,-1,-1,0,0,1,1,1};
const int dy[] = {-1,0,1,-1,1,-1,0,1};

struct UnionFind{
    vector<int> par, siz;

    UnionFind(int n){
        par.assign(n,-1);
        siz.assign(n,0);
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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    UnionFind uf(h*w);
    rep(i,h)rep(j,w){
        if(s[i][j] == '#'){
            rep(k,8){
                int ni = i+dx[k], nj = j+dy[k];
                if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
                if(s[ni][nj] == '.') continue;
                if(!uf.same(i*w+j,ni*w+nj)) uf.unite(i*w+j,ni*w+nj);
            }
        }
    }
    int ans = 0;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#'){
            if(uf.root(i*w+j) == i*w+j) ans++;
        }
    }
    cout << ans << el;
    return 0;
}
