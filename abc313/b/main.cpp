#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int n;
vector<bool> visited;

void dfs(const vector<vector<int>>& g, int now){
    if(visited[now]) return;
    visited[now] = true;
    for(int nxt : g[now]){
        if(visited[nxt]) continue;
        dfs(g, nxt);
    }
}

int main(){
    int m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    rep(i,n){
        visited.assign(n,false);
        dfs(g,i);
        bool ok = true;
        rep(j,n) if(!visited[j]) ok = false;
        if(ok){
            cout << i+1 << el;
            return 0;
        }
    }
    cout << -1 << el;
    return 0;
}
