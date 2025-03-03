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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> ans;
    rep(i,n){
        if(a[i] <= l)ans.push_back(l);
        else if(a[i] >= r) ans.push_back(r);
        else ans.push_back(a[i]);
    }
    rep(i,ans.size()) cout << ans[i] << (i==(int)ans.size()-1?'\n':' ');
    return 0;
}
