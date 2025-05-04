// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = (1<<30);
const ll LLINF = (1LL<<60);
// }}}

int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  rep(i,n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> v(k);
  set<int> vs;
  rep(i,k){
    cin >> v[i];
    v[i]--;
    vs.insert(v[i]);
  }
  vector<bool> visited(n), check(n);

  auto dfs = [&](auto dfs, int pos, int prev=-1) -> bool {
    visited[pos] = true;
    bool res = vs.count(pos) ? true : false;
    for(int nxt : g[pos]){
      if(nxt == prev) continue;
      if(visited[nxt]){
        res |= check[nxt];
        continue;
      }
      res |= dfs(dfs, nxt, pos);
    }
    return check[pos] = res;
  };

  dfs(dfs, v[0]);
  int ans = 0;
  rep(i,n) if(check[i]) ans++;
  cout << ans << el;
  return 0;
}
