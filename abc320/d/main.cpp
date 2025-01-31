#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,P>>> g(n);
    rep(i,m){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        a--; b--;
        g[a].emplace_back(b,P(x,y));
        g[b].emplace_back(a,P(-x,-y));
    }
    queue<int> q;
    q.push(0);
    vector<bool> visited(n);
    vector<pair<ll,ll>> ans(n);
    ans[0] = {0,0};
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(visited[now]) continue;
        visited[now] = true;
        for(auto [nxt,np] : g[now]){
            if(visited[nxt]) continue;
            auto [f,s] = np;
            if(nxt!=0 && ans[nxt].first==0 && ans[nxt].second==0){
                ans[nxt] = {ans[now].first+f, ans[now].second+s};
            }
            q.push(nxt);
        }
    }
    rep(i,n){
        if(!visited[i]) cout << "undecidable" << el;
        else cout << ans[i].first << " " << ans[i].second << el;
    }
    return 0;
}
