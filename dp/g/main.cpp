// G - Longest Path
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

int dp[100005];

vector<int> topo_sort(const vector<vector<int>>& g, vector<int>& inde, int n){
    vector<int> topo;
    queue<int> q;
    // 入次数0の頂点をキューに追加
    rep(i,n) if(inde[i] == 0) q.push(i);
    while(!q.empty()){
        int v = q.front(); q.pop();
        // 今見ている頂点(入次数は0)を配列に追加
        topo.push_back(v);
        // 入次数0の頂点と繋がっている頂点の入次数1つ減らし、0になればキューに追加
        for(int nxt : g[v]){
            inde[nxt]--;
            if(inde[nxt] == 0) q.push(nxt);
        }
    }
    return topo;
}

// 解説見るとメモ化再帰でも求められる
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> inde(n);
    rep(i,m){
        int x, y; cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        inde[y]++;
    }
    vector<int> topo = topo_sort(g, inde, n);
    rep(i,topo.size()){
        for(int nxt : g[topo[i]]) dp[nxt] = max(dp[nxt], dp[topo[i]]+1);
    }
    int ans = 0;
    rep(i,n) ans = max(ans, dp[i]);
    cout << ans << el;
    return 0;
}