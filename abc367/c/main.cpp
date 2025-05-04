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
  vector<int> r(n);
  rep(i,n) cin >> r[i];

  vector<vector<int>> ans;

  auto f = [&](auto f, int num, vector<int> v) -> void{
    if(num == n){
      if((int)v.size() == n){
        int sum = 0;
        rep(i,v.size()) sum += v[i];
        if(sum%k == 0) ans.push_back(v);
      }
      return;
    }

    repi(i,1,r[num]+1){
      v.push_back(i);
      f(f, num+1, v);
      v.pop_back();
    }
  };

  repi(i,1,r[0]+1){
    vector<int> v = {i};
    f(f, 1, v);
  }

  rep(i,ans.size()){
    rep(j,ans[i].size()) printf("%d%c", ans[i][j], j==(int)ans[i].size()-1?'\n':' ');
  }
  return 0;
}
