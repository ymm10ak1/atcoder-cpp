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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<vector<int>> g(n);
    rep(i,m){ cin >> a[i]; a[i]--; }
    rep(i,m){ cin >> b[i]; b[i]--; }
    rep(i,m){
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    vector<int> x(n,-1);
    vector<bool> visited(n);

    auto dfs = [&](auto dfs, int now){
        if(visited[now]) return;
        visited[now] = true;
        if(x[now] == -1) x[now] = 0;
        for(int nxt : g[now]){
            if(visited[nxt]) continue;
            if(x[nxt] == -1){
                x[nxt] = !x[now];
                dfs(dfs, nxt);
            }
        }
    };

    rep(i,n) if(!visited[i]) dfs(dfs,i);
    bool ok = true;
    rep(i,m) if((x[a[i]]^x[b[i]]) == 0) ok = false;
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
