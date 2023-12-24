// 
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

// 以下はWA解
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    deque<int> q;
    rep(i, m) q.push_back(a[i]);
    ll max_v = 0;
    rep(i, m) max_v += q[i]*(i+1);
    repi(i, m, n){
        ll v = 0;
        q.pop_front();
        q.push_back(a[i]);
        rep(i, m) v += q[i]*(i+1);
        max_v = max(max_v, v);
    }
    cout << max_v << el;
    return 0;
}