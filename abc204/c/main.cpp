// C - Tour
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int cnt = 0;
vector<bool> seen;

void dfs(const vector<vector<int>> &g, int v){
    seen[v] = true;
    for(auto next_v : g[v]){
        if(seen[next_v]) continue;
        dfs(g, next_v);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    seen.assign(n, false);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    seen.assign(n, false);
    vector<bool> init_seen(n, false);
    int cnt = 0;
    // 各頂点を始点と終点にしてdfsする
    rep(i, n){
        seen = init_seen;
        rep(j, n){
            dfs(g, i);
            if(seen[j]) cnt++;
        }
    }
    cout << cnt << el;
    return 0;
}