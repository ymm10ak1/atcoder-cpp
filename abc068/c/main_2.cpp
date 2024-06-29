// C - Cat Snuke and a Voyage
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
    vector<vector<int>> g(n);
    rep(i,m){
        int a, b; cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(0);
    bool first = true;
    int siz = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        visited[v] = true;
        if(!first && siz==0) continue;
        for(int nxt : g[v]){
            if(visited[nxt]) continue;
            q.push(nxt);
        }
        if(siz > 0) siz--;
        if(first){
            siz = q.size();
            first = false;
        }
    }
    if(visited[n-1]) cout << "POSSIBLE" << el;
    else cout << "IMPOSSIBLE" << el;
    return 0;
}
