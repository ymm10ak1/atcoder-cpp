// D - Line++
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

vector<int> bfs(const vector<vector<int>> &g, int s){
    queue<int> qu;
    vector<int> dist(g.size(), -1);
    
    dist[s] = 0;
    qu.push(s);
    
    while(!qu.empty()){
        int v = qu.front();
        qu.pop();

        for(auto next : g[v]){
            if(dist[next] != -1) continue;
            qu.push(next);
            dist[next] = dist[v]+1;
        }
    }
    return dist;
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> g(n);
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
    rep(i, n-1){
        g[i].push_back(i+1);
        g[i+1].push_back(i);
    }
    vector<int> cnt(n, 0);
    rep(i, n-1){
        vector<int> dist = bfs(g, i);
        repi(j, i+1, dist.size()){
            if(dist[j] != -1) cnt[dist[j]]++;
        }
    }
    repi(i, 1, n){
        cout << cnt[i] << el;
    }
    return 0;
}