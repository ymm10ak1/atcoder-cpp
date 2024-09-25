// D - Shortest Path 3
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

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<pair<int,ll>>> g(n);
    rep(i,m){
        int u, v, b;
        cin >> u >> v >> b;
        --u; --v;
        g[u].push_back({v,b+a[v]});
        g[v].push_back({u,b+a[u]});
    }
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    vector<ll> cost(n,LLINF);
    vector<bool> kakutei(n);
    cost[0] = a[0];
    q.push({cost[0],0});
    while(!q.empty()){
        int now = q.top().second; q.pop();
        if(kakutei[now]) continue;
        kakutei[now] = true;
        for(auto nxt : g[now]){
            if(cost[nxt.first] > cost[now]+nxt.second){
                cost[nxt.first] = cost[now]+nxt.second;
                q.push({cost[nxt.first],nxt.first});
            }
        }
    }
    repi(i,1,n) printf("%lld%c", cost[i], i==n-1?'\n':' ');
    return 0;
}
