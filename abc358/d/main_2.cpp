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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(all(b));
    map<int,int> mp;
    for(int ai : a) mp[ai]++;
    ll ans = 0;
    rep(i,m){
        auto it = mp.lower_bound(b[i]);
        if(it == mp.end()){
            cout << -1 << el;
            return 0;
        }
        int x = (it->first);
        ans += x;
        if(--mp[x] == 0) mp.erase(x);
    }
    cout << ans << el;
    return 0;
}
