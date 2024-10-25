// E
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

int main(){
    int n, mg;
    cin >> n >> mg;
    vector<vector<bool>> g(n,vector<bool>(n));
    rep(i,mg){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u][v] = g[v][u] = true;
    }
    int mh; cin >> mh;
    vector<vector<bool>> h(n,vector<bool>(n));
    rep(i,mh){
        int a, b;
        cin >> a >> b;
        --a, --b;
        h[a][b] = h[b][a] = true;
    }
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n-1) repi(j,i+1,n) cin >> a[i][j];
    vector<int> p(n);
    rep(i,n) p[i] = i;
    int ans = INF;
    do{
        int price = 0;
        rep(i,n-1){
            repi(j,i+1,n){
                if(g[i][j] && h[p[i]][p[j]]) continue;
                // gに辺が存在してhに存在しない場合は辺の追加
                if(g[i][j] && !h[p[i]][p[j]]){
                    int pi = p[i], pj = p[j];
                    if(pi > pj) swap(pi,pj);
                    price += a[pi][pj];
                }
                // gに辺が存在せずhに存在する場合は辺の削除
                if(!g[i][j] && h[p[i]][p[j]]){
                    int pi = p[i], pj = p[j];
                    if(pi > pj) swap(pi,pj);
                    price += a[pi][pj];
                }
            }
        }
        ans = min(ans, price);
    }while(next_permutation(all(p)));
    if(ans == INF) ans = 0;
    cout << ans << el;
    return 0;
}
