// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = (1<<30);
const ll LLINF = (1LL<<60);
// }}}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> visited(n);
    set<P> st;

    auto dfs = [&](auto dfs, int cur, int prev) -> void{
        if(visited[cur]) return;
        visited[cur] = true;
        for(int nxt : g[cur]){
            if(nxt != prev && prev != -1 && visited[nxt]){
                int a = cur, b = nxt;
                if(cur > nxt) swap(a, b);
                st.emplace(a,b);
            }
            if(visited[nxt]) continue;
            dfs(dfs, nxt, cur);
        }
    };

    rep(i,n){
        if(!visited[i]) dfs(dfs, i, -1);
    }
    cout << st.size() << el;
    return 0;
}
