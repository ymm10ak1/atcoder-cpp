// 
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

// NOTE: 浮動小数点数だと怖いので整数で比較したほうがいい
// c++の場合、stable_sortの比較関数でa[i]/(a[i]+b[i])とa[j]/(a[j]+b[j])をa[i]*(a[j]+b[j])とa[j]*(a[i]+b[i])の大きい順で比較するようにする
// 安定ソート(c++ではstable_sort)だと順位が同じ複数のデータのソート前の前後関係がソート後も保存される
int main(){
    int n; cin >> n;
    vector<long double> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<pair<long double,int>> vp;
    rep(i,n) vp.emplace_back(a[i]/(a[i]+b[i]),-(i+1));
    sort(rall(vp));
    rep(i,n) printf("%d%c", -vp[i].second, i==n-1?'\n':' ');
    return 0;
}
