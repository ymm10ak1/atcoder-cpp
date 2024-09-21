// C - Path Graph?
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
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int e1 = 0, e2 = 0;
    int sta = 0;
    rep(i,n){
        if(g[i].size() == 1){
            sta = i;
            e1++;
        }else if(g[i].size() == 2){
            e2++;
        }
    }
    if(e1!=2 || e2!=n-2){
        cout << "No" << el;
        return 0;
    }
    vector<bool> used(n,false);
    queue<int> q;
    q.push(sta);
    used[sta] = true;
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int nxt : g[now]){
            if(used[nxt]) continue;
            used[nxt] = true;
            q.push(nxt);
        }
    }
    bool ok = true;
    rep(i,n) if(!used[i]) ok = false;
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
