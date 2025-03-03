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
    int sv = 0;
    rep(i,n){
        int ai; cin >> ai;
        if(ai == -1){
            sv = i;
            continue;
        }
        ai--;
        g[ai].push_back(i);
    }
    vector<bool> visited(n);
    vector<int> ans;

    auto dfs = [&](auto dfs, int v) -> void{
        if(visited[v]) return;
        visited[v] = true;
        ans.push_back(v+1);
        for(int u : g[v]){
            if(visited[u]) continue;
            dfs(dfs, u);
        }
    };

    dfs(dfs, sv);
    rep(i,ans.size()) printf("%d%c", ans[i], i==(int)ans.size()-1?'\n':' ');
    return 0;
}
