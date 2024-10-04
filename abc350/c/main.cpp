// C - Sort
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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int,int> mp;
    rep(i,n) mp[a[i]] = i;
    vector<pair<int,int>> ans;
    rep(i,n){
        if(a[i] == i+1) continue;
        int idx = mp[i+1];
        if(idx <= i) continue;
        ans.push_back({i+1,idx+1});
        mp[a[i]] = idx;
        mp[a[idx]] = i;
        swap(a[i],a[idx]);
    }
    cout << ans.size() << el;
    for(auto [x,y] : ans) printf("%d %d\n", x, y);
    return 0;
}
