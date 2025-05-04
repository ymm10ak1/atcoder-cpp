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
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  priority_queue<int> q;
  rep(i,n) q.push(a[i]);
  int ans = 0;
  while(!q.empty()){
    int a0 = q.top(); q.pop();
    int a1 = 0;
    if(!q.empty()){
      a1 = q.top(); q.pop();
      if(a1 <= 0) break;
    }
    q.push(a0-1);
    q.push(a1-1);
    ans++;
  }
  cout << ans << el;
  return 0;
}
