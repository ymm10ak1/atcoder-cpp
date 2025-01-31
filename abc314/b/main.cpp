#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
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
    vector<vector<int>> a(n);
    rep(i,n){
        int c; cin >> c;
        rep(j,c){
            int ai; cin >> ai;
            a[i].push_back(ai);
        }
    }
    int x; cin >> x;
    vector<int> h;
    rep(i,n)rep(j,a[i].size()){
        if(a[i][j] == x) h.push_back(i);
    }
    int m = h.size();
    vector<int> ans;
    rep(i,m){
        bool ok = true;
        rep(j,m){
            if(i == j) continue;
            if(a[h[i]].size() > a[h[j]].size()) ok = false;
        }
        if(ok) ans.push_back(h[i]);
    }
    sort(all(ans));
    cout << ans.size() << el;
    rep(i,ans.size()) cout << ans[i]+1 << ' ';
    cout << el;
    return 0;
}
