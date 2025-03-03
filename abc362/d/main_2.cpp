// {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;
// }}}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    using PL = pair<ll,int>;
    vector<vector<PL>> g(n);
    rep(i,m){
        int u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        g[u].emplace_back(b+a[v],v);
        g[v].emplace_back(b+a[u],u);
    }
    vector<ll> dist(n,LLINF);
    vector<bool> kakutei(n);
    priority_queue<PL,vector<PL>,greater<PL>> q; 
    dist[0] = a[0];
    q.emplace(dist[0],0);
    while(!q.empty()){
        auto [cost, now] = q.top(); q.pop();
        if(kakutei[now]) continue;
        kakutei[now] = true;
        for(auto [ncost, nxt] : g[now]){
            if(dist[nxt] > ncost+cost){
                dist[nxt] = ncost+cost;
                q.emplace(dist[nxt], nxt);
            }
        }
    }
    repi(i,1,n) printf("%lld%c", dist[i], i==n-1?'\n':' ');
    return 0;
}
