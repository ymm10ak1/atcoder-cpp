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

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i,n-1){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> visited(n);
    visited[0] = true;

    auto dfs = [&](auto dfs, int now){
        if((int)g[now].size() == 1) return 1;
        visited[now] = true;
        int cnt = 1;
        for(int nxt : g[now]){
            if(visited[nxt]) continue;
            cnt += dfs(dfs,nxt);
        }
        return cnt;
    };

    int mx = 0, ans = 0;
    for(int v : g[0]){
        int cnt = dfs(dfs, v);
        mx = max(mx, cnt);
        ans += cnt;
    }
    ans -= mx;
    ans++;
    cout << ans << el;
    return 0;
}
