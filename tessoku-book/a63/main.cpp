// Shortest Path 1
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

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> ans(n, -1);
    queue<int> q;
    ans[0] = 0;
    q.push(0);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int nxt : g[v]){
            if(ans[nxt] != -1) continue;
            ans[nxt] = ans[v]+1;
            q.push(nxt);
        }
    }
    rep(i,n) cout << ans[i] << el;
    return 0;
}