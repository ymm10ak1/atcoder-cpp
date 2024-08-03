// E - ゾンビ島(Zombie Island)
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

bool kiken[100005], zombie[100005];
int dist[100005];

template <typename T>
bool chmin(T& a, T b){
    if(a > b){ a = b; return true; }
    return false;
}

void bfs(const vector<vector<int>>& g, queue<int>& q, const int n){
    vector<bool> visited(n, false);
    while(!q.empty()){
        int now = q.front(); q.pop();
        visited[now] = true;
        for(int nxt : g[now]){
            if(visited[nxt]) continue;
            if(chmin(dist[nxt], dist[now]+1)) q.push(nxt);
        }
    }
}

ll dijkstra(const vector<vector<int>>& g, const int n, const int p, const int q){
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> qu;
    vector<ll> cost(n, LLINF);
    vector<bool> kakutei(n, false);
    cost[0] = 0;
    qu.push({cost[0], 0});
    while(!qu.empty()){
        int now = qu.top().second; qu.pop();
        if(kakutei[now]) continue;
        kakutei[now] = true;
        for(int nxt : g[now]){
            if(zombie[nxt]) continue;
            int price = 0;
            if(nxt < n-1) price = kiken[nxt] ? q : p;
            if(cost[nxt] > cost[now]+price){
                cost[nxt] = cost[now]+price;
                qu.push({cost[nxt], nxt});
            }
        }
    }
    return cost[n-1];
}

int main(){
    int n, m, k, s, p, q;
    cin >> n >> m >> k >> s >> p >> q;
    vector<int> c(k);
    rep(i,k){
        cin >> c[i]; --c[i];
        zombie[c[i]] = true;
    }
    vector<vector<int>> g(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> que;
    rep(i,n) dist[i] = INF;
    rep(i,k){
        que.push(c[i]);
        dist[c[i]] = 0;
    }
    // 危険な町を調べる
    bfs(g, que, n);
    rep(i,n) if(dist[i]>=1 && dist[i]<=s) kiken[i] = true;
    cout << dijkstra(g, n, p, q) << el;
    return 0;
}