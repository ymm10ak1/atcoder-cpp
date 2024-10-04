// D - Takahashi Tour
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

bool used[200005];
vector<int> ans;

void dfs(const vector<set<int>>& g, int now){
    ans.push_back(now);
    used[now] = true;
    for(int nxt : g[now]){
        if(used[nxt]) continue;
        dfs(g, nxt);
        ans.push_back(now);
    }
}

int main(){
    int n; cin >> n;
    vector<set<int>> g(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].insert(b);
        g[b].insert(a);
    }
    dfs(g, 0);
    rep(i,ans.size()) printf("%d%c", ans[i]+1, i==(int)ans.size()-1?'\n':' ');
    return 0;
}
