#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<P> a(n);
    ll sum = 0;
    map<int,int> mp;
    rep(i,n){
        cin >> a[i].first;
        a[i].second = i;
        sum += a[i].first;
        mp[a[i].first]++;
    }
    sort(all(a));
    vector<ll> ans(n);
    rep(i,n){
        sum -= (ll)a[i].first*mp[a[i].first];
        mp.erase(a[i].first);
        ans[a[i].second] = max(sum, 0LL);
    }
    rep(i,n) printf("%lld%c", ans[i], i==n-1?'\n':' ');
    return 0;
}
