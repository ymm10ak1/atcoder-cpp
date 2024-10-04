// A - 2nd Greatest Distance
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

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<pair<int,int>> px, py;
    rep(i,n){
        px.push_back({x[i],i});
        py.push_back({y[i],i});
    }
    sort(rall(px));
    sort(rall(py));
    map<pair<int,int>,int> mp;
    auto f = [&](vector<pair<int,int>>& a){
        rep(i,3){
            int ai1 = a[i].second, ai2 = a[n-1].second;
            if(ai1 > ai2) swap(ai1, ai2);
            mp[{ai1,ai2}] = max(mp[{ai1,ai2}], abs(a[i].first-a[n-1].first));
        }
        rep(i,3){
            int ai1 = a[n-1-i].second, ai2 = a[0].second;
            if(ai1 > ai2) swap(ai1, ai2);
            mp[{ai1,ai2}] = max(mp[{ai1,ai2}], abs(a[n-1-i].first-a[0].first));
        }
    };
    f(px);
    f(py);
    vector<int> ans;
    for(auto [k,v] : mp) ans.push_back(v);
    sort(rall(ans));
    cout << ans[1] << el;
    return 0;
}
