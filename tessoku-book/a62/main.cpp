// A62 - Depth First Search
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

set<int> st;
bool seen[100010];

void dfs(const vector<vector<int>>& g, int v){
    st.insert(v);
    seen[v] = true;
    for(int next_v : g[v]){
        if(seen[next_v]) continue;
        dfs(g, next_v);
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m){
        int a, b; cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(g, 0);
    int cnt = 0;
    rep(i,n) if(seen[i]) ++cnt;
    if(cnt == n) cout << "The graph is connected." << el;
    else cout << "The graph is not connected." << el;
    return 0;
}