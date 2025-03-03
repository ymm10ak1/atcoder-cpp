#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> a(t);
    rep(i,t) cin >> a[i];
    map<int,int> mp;
    rep(i,t) mp[a[i]-1] = i+1;
    int ans = INF;
    rep(i,n){
        int r = 0, c = 0;
        bool ok = true;
        rep(j,n){
            if(mp[i*n+j] > 0) r = max(r, mp[i*n+j]);
            else{ ok = false; break; }
        }
        if(ok) ans = min(ans, r);
        ok = true;
        rep(j,n){
            if(mp[j*n+i] > 0) c = max(c, mp[j*n+i]);
            else{ ok = false; break; }
        }
        if(ok) ans = min(ans, c);
    }
    // 斜め
    bool ok = true; int na = 0;
    rep(i,n){
        if(mp[i*n+i] > 0) na = max(na, mp[i*n+i]);
        else{ ok = false; break; }
    }
    if(ok) ans = min(ans, na);
    ok = true; na = 0;
    rep(i,n){
        if(mp[i*n+(n-1-i)] > 0) na = max(na ,mp[i*n+(n-1-i)]);
        else{ ok = false; break; }
    }
    if(ok) ans = min(ans, na);
    cout << (ans==INF?-1:ans) << el;
    return 0;
}
