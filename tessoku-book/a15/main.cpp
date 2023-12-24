// A15 - Compression
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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> t;
    rep(i, n) t.push_back(a[i]);
    sort(all(t));
    // 重複を消す
    t.erase(unique(all(t)), t.end());
    vector<int> b(n);
    rep(i, n){
        int idx = (lower_bound(all(t), a[i])-t.begin())+1;
        b[i] = idx;
    }
    rep(i, n) printf("%d%c", b[i], i==n-1?'\n':' ');
    return 0;
}