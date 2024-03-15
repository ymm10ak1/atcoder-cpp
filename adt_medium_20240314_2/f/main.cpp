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


void dfs(const vector<vector<int>>& g, int v, const int sta){
    
}

// 解法が思いつかなかった
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<bool>> check(n,vector<bool>(n,false));
    rep(i,m){
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        check[u][v] = true;
        check[v][u] = true;
    }
    bool ok = false;
    rep(i,n){
        if(g[i].size() != 1) continue;
    }
    return 0;
}