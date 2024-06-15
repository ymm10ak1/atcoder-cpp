// C - Not so Diverse
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    rep(i,n){
        cin >> a[i];
        ++mp[a[i]];
    }
    if((int)mp.size() <= k){
        cout << 0 << el;
        return 0;
    }
    vector<pair<int,int>> vp;
    for(auto p : mp) vp.push_back({p.second, p.first});
    sort(all(vp));
    int ans = 0, sta = (int)mp.size();
    rep(i,vp.size()){
        ans += vp[i].first;
        --sta;
        if(sta <= k) break;
    }
    cout << ans << el;
    return 0;
}
