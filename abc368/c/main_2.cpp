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
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  ll t = 0;
  rep(i,n){
    t += (ll)(h[i]/5)*3;
    h[i] %= 5;
    while(h[i] > 0){
      t++;
      if(t%3 == 0) h[i] -= 3;
      else h[i]--;
    }
  }
  cout << t << el;
  return 0;
}
