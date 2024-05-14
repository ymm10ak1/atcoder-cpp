// B65 - Road to Promotion Hard
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

int dist[100005], dp[100005];
bool kakutei[100005];

void bfs(const vector<vector<int>>& g, int t){
    queue<int> q;
    q.push(t);
    dist[t] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int nxt : g[v]){
            if(dist[nxt] == -1){
                dist[nxt] = dist[v]+1;
                q.push(nxt);
            }
        }
    }
}

// 解説見るとDFS(深さ優先探索)のほうが実装しやすそう
int main(){
    int n, t;
    cin >> n >> t;
    --t;
    vector<vector<int>> g(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,100005) dist[i] = -1;
    // bfsで始点tから各頂点への距離を求める
    bfs(g,t);
    vector<pair<int, int>> vp;
    rep(i,n) vp.push_back({dist[i], i});
    // 距離の長い順にソートする
    sort(rall(vp));
    rep(i,vp.size()){
        int idx = vp[i].second;
        dp[idx] = 0;
        kakutei[idx] = true;
        for(int x : g[idx]){
            dp[idx] = max(dp[idx],dp[x]+1);
        }
    }
    rep(i,n) printf("%d%c",dp[i]-1,i==n-1?'\n':' ');
    return 0;
}