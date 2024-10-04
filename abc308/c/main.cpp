// C - Standings
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

// NOTE: 解説見るとa[i]*(a[j]+b[j])>a[j]*(a[i]+b[i])で整数にして比較を行っている
// 添字だけを格納した配列を用意してsortを行う。そのときに上記の式を比較関数に書けばいい
int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<pair<long double,int>> vp;
    rep(i,n){
        long double div = (long double)a[i]/(a[i]+b[i]);
        vp.push_back({div, -i});
    }
    sort(rall(vp));
    rep(i,n) printf("%d%c", -vp[i].second+1, i==n-1?'\n':' ');
    return 0;
}
