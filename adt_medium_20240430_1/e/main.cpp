// E - Coverage
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a;
    rep(i,m){
        int cc; cin >> cc;
        vector<int> aa(cc);
        rep(j,cc) cin >> aa[j];
        a.push_back(aa);
    }
    int ans = 0;
    rep(bit, (1<<m)){
        vector<int> cnt(n,0);
        rep(i,m){
            if(bit & (1<<i)){
                rep(j,a[i].size()) ++cnt[a[i][j]-1];
            }
        }
        bool ok = true;
        rep(i,n) if(cnt[i]<=0) ok = false;
        if(ok) ++ans;
    }
    cout << ans << el;
    return 0;
}