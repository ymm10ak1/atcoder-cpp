#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

// NOTE: ヒントを見て解いたので自力で解けていない
int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i,n){
        int c; cin >> c;
        rep(j,c){
            int p; cin >> p;
            p--;
            g[i].push_back(p);
        }
    }
    vector<bool> visited(n);
    vector<P> last_order(n,P(-INF,-INF));
    int cnt = 0;

    auto dfs = [&](auto dfs, int now) -> void{
        visited[now] = true;
        for(int nxt : g[now]){
            if(visited[nxt]) continue;
            dfs(dfs, nxt);
        }
        last_order[now].first = cnt++;
        last_order[now].second = now;
    };

    dfs(dfs, 0);
    sort(all(last_order));
    vector<int> ans;
    rep(i,n){
        if(last_order[i].first==-INF || last_order[i].second==0) continue;
        ans.push_back(last_order[i].second+1);
    }
    rep(i,ans.size()) printf("%d%c", ans[i], i==(int)ans.size()-1?'\n':' ');
    return 0;
}
