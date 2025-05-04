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
  // NOTE: ヒントありで書いた
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> s(2*n);
  rep(i,2*n-1) s[i+1] = s[i]+a[i%n];
  vector<int> ma(m);

  // 解説を見て実装したもの
  // rep(i,n) ma[s[i]%m]++; // ここでans+=ma[s[i]%m]をしていたので2周目でも同じ(s,t)の区間を求めていた可能性が高い
  // ll ans = 0;
  // 2回以上同じ区間を求めないためには1週目ではなく2週目の休憩所1からmodMの個数を答えに加えること
  // repi(i,n,2*n){
  //   ma[s[i-n]%m]--;
  //   ans += ma[s[i]%m];
  //   ma[s[i]%m]++;
  // }

  ll ans = 0;
  rep(i,2*n-1){
    if(i>=n && ma[s[i-n]%m]>0) ma[s[i-n]%m]--;
    ans += ma[s[i]%m];
    if(i < n) ma[s[i]%m]++;
  }
  cout << ans << el;
  return 0;
}
