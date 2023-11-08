// D - ..(Double Dots)
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

vector<int> q;

vector<int> bfs(const vector<vector<int>>& g, int s){
    queue<int> que;
    vector<int> dist(g.size(), -1);

    // 幅優先探索の初期条件
    dist[s] = 0;
    que.push(s);

    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(auto next : g[v]){
            if(dist[next] != -1) continue;
            que.push(next);
            dist[next] = dist[v]+1;
            q[next] = v+1;
        }
    }
    return dist;
}

int main(){
    int n, m;
    cin >> n >> m;
    q.resize(n);
    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist = bfs(g, 0);
    rep(i, dist.size()){
        if(dist[i] == -1){
            cout << "No" << el;
            return 0;
        }
    }
    cout << "Yes" << el;
    repi(i, 1, n){
        cout << q[i] << el;
    }
    return 0;
}