// B62 - Print a Path
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

bool visited[100005];
int previous[100005];

void dfs(const vector<vector<int>>& g, int pos){
    visited[pos] = true;
    for(int nxt : g[pos]){
        if(visited[nxt]) continue;
        dfs(g, nxt);
        previous[nxt] = pos;
    }
}

// 解説見るとスタックで経路を管理していたのでそちらで実装できるようにする
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(g,0);
    previous[0] = -1;
    int now = n-1;
    vector<int> ans;
    ans.push_back(now+1);
    while(previous[now] != -1){
        now = previous[now];
        ans.push_back(now+1);
    }
    rrepi(i,ans.size(),0){
        if(i > 0) cout << ans[i] << " ";
        else cout << ans[i] << el;
    }
    return 0;
}