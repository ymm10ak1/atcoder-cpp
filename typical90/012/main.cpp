// 012 - Red Painting（★4）
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

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

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
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> red(h, vector<bool>(w, false));
    UnionFind uf(h*w);
    rep(i,q){
        int t; cin >> t;
        if(t == 1){
            int r, c; cin >> r >> c;
            --r; --c;
            red[r][c] = true;
            // 上下左右のマスが赤色ならば結合する
            rep(d,4){
                int nr = r+dx[d], nc = c+dy[d];
                if(nr<0 || nr>=h || nc<0 || nc>=w) continue;
                if(red[nr][nc]) uf.unite(r*w+c, nr*w+nc);
            }
        }else{
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            --r1; --c1; --r2; --c2;
            bool ok = true;
            if(!red[r1][c1] || !red[r2][c2]) ok = false;
            if(ok){
                if(!uf.issame(r1*w+c1, r2*w+c2)) ok = false;
            }
            if(ok) cout << "Yes" << el;
            else cout << "No" << el;
        }
    }
    return 0;
}
