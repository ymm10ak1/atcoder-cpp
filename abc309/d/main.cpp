// 
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
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    vector<vector<int>> g(n1+n2);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n1+n2, INF);
    vector<bool> visited(n1+n2);
    auto bfs = [&](int sta){
        queue<int> q;
        q.push(sta);
        dist[sta] = 0;
        while(q.size()){
            int now = q.front(); q.pop();
            if(visited[now]) continue;
            visited[now] = true;
            for(int nxt : g[now]){
                if(visited[nxt]) continue;
                q.push(nxt);
                dist[nxt] = min(dist[nxt], dist[now]+1);
            }
        }
    };
    bfs(0);
    bfs(n1+n2-1);
    int d1 = 0, d2 = 0;
    rep(i,n1)  d1 = max(d1, dist[i]);
    repi(i,n1,n1+n2) d2 = max(d2, dist[i]);
    cout << d1+d2+1 << el;
    return 0;
}
