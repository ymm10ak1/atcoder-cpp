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
    int n; cin >> n;
    vector<int> a(n), c(n);
    rep(i,n) cin >> a[i] >> c[i];
    map<int,int> mp;
    rep(i,n){
        if(mp[c[i]] > 0) mp[c[i]] = min(mp[c[i]], a[i]);
        else mp[c[i]] = a[i];
    }
    int ans = 0;
    for(auto [_, ai] : mp) ans = max(ans, ai);
    cout << ans << el;
    return 0;
}
