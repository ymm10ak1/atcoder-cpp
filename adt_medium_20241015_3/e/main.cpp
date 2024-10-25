// E
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

vector<bool> used;
vector<int> t;
ll ans = 0;

void dfs(const vector<vector<int>>& g, int now){
    used[now] = true;
    ans += t[now];
    for(int nxt : g[now]){
        if(used[nxt]) continue;
        dfs(g, nxt);
    }
}

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    t.resize(n,0);
    used.resize(n,false);
    rep(i,n){
        int k;
        cin >> t[i] >> k;
        rep(j,k){
            int ai; cin >> ai;
            g[i].push_back(ai-1);
        }
    }
    dfs(g,n-1);
    cout << ans << el;
    return 0;
}
