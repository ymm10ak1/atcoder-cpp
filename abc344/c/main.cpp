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

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int m; cin >> m;
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    int l; cin >> l;
    vector<int> c(l);
    rep(i,l) cin >> c[i];
    int q; cin >> q;
    vector<int> x(q);
    map<int, bool> mp, res;
    rep(i,q){
        cin >> x[i];
        mp[x[i]] = true;
        res[x[i]] = false;
    }
    rep(i,n){
        rep(j,m){
            rep(k,l){
                int sum = a[i]+b[j]+c[k];
                if(mp[sum]) res[sum] = true;
            }
        }
    }
    rep(i,q){
        if(res[x[i]]) cout << "Yes" << el;
        else cout << "No" << el;
    }
    return 0;
}