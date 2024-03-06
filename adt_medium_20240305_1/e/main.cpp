// 
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

int c[15][15];
vector<bool> seen;
int ans = 0;

void dfs(const vector<vector<int>> &g, int sta, int sum){
    // 頂点sta来たときにtrue
    seen[sta] = true;
    ans = max(ans, sum);
    for(auto next : g[sta]){
        if(seen[next]) continue;
        dfs(g, next, sum+c[sta][next]);
    }
    // 頂点staを離れるときfalse
    seen[sta] = false;
}

// DFSなのはわかったが実装ができなかった(再帰関数の実装が難しい)
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    // 重み付き無向グラフ
    rep(i,m){
        int a, b, ci;
        cin >> a >> b >> ci;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
        c[a][b] = ci;
        c[b][a] = ci;
    }
    seen.assign(n, false);
    rep(i,n){
        rep(j,n) seen[j] = false;
        dfs(g, i, 0);
    }
    cout << ans << el;
    return 0;
}