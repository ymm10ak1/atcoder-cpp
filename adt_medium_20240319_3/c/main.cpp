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
    vector<bool> cnt(n, false);
    rep(i,n){
        if(!cnt[i]) cnt[a[i]-1] = true;
    }
    vector<int> ans;
    rep(i,n) if(!cnt[i]) ans.push_back(i+1);
    cout << ans.size() << el;
    rep(i,ans.size()) printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    return 0;
}