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

int n, sta;
vector<bool> visited;
vector<int> ans;

void dfs(const vector<vector<int>>& g, int now, bool flag){
    if(visited[now]) return;
    if(flag) ans.push_back(now);
    visited[now] = true;
    for(int nxt : g[now]){
        if(visited[nxt]){
            sta = nxt;
            continue;
        }
        dfs(g,nxt,flag);
    }
}

int main(){
    cin >> n;
    vector<vector<int>> g(n);
    rep(i,n){
        int a; cin >> a;
        a--;
        g[i].push_back(a);
    }
    visited.assign(n,false);
    rep(i,n){
        if(visited[i]) continue;
        sta = -1;
        dfs(g, i, false);
        if(sta != -1) break;
    }
    visited.assign(n,false);
    dfs(g, sta, true);
    cout << ans.size() << el;
    rep(i,ans.size()) printf("%d%c", ans[i]+1, i==(int)ans.size()-1?'\n':' ');
    return 0;
}
