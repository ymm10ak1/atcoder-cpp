// A14 - Four Boxes
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n), d(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> d[i];
    // 配列pを作成
    vector<int> p;
    rep(i, n){
        rep(j, n) p.push_back(a[i]+b[j]);
    }
    // 配列qを作成
    vector<int> q;
    rep(i, n){
        rep(j, n) q.push_back(c[i]+d[j]);
    }
    // 配列qを小さい順にソート
    sort(all(q));
    // 二分探索
    rep(i, p.size()){
        int ps = lower_bound(all(q), k-p[i])-q.begin();
        if(q[ps] == k-p[i]){
            cout << "Yes" << el;
            return 0;
        }
    }
    cout << "No" << el;
    return 0;
}