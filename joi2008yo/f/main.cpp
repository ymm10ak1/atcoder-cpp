// F - 船旅
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

vector<int> dijkstra(const vector<vector<pair<int,int>>>& g, const int n, int a, int b){
    vector<int> cost(n, INF);
    vector<bool> kakutei(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    cost[a] = 0;
    q.push({cost[a], a});
    while(!q.empty()){
        int now = q.top().second; q.pop();
        if(kakutei[now]) continue;
        kakutei[now] = true;
        for(pair<int,int> nxt : g[now]){
            int ni = nxt.first;
            if(cost[ni] > cost[now]+nxt.second){
                cost[ni] = cost[now]+nxt.second;
                q.push({cost[ni], ni});
            }
        }
    }
    return cost;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int,int>>> g(n);
    rep(i,k){
        int t, a, b;
        cin >> t >> a >> b;
        --a; --b;
        if(t == 0){
            vector<int> cost = dijkstra(g,n,a,b);
            if(cost[b] == INF) cout << -1 << el;
            else cout << cost[b] << el;
        }else if(t == 1){
            int e; cin >> e;
            g[a].push_back({b,e});
            g[b].push_back({a,e});
        }
    }
    return 0;
}