// C - Skill Up
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n){
        cin >> c[i];
        rep(j, m) cin >> a[i][j];
    }
    int ans = INF;
    rep(bit, (1<<n)){
        vector<int> sum(m, 0);
        int v = 0;
        rep(i, n){
            if(bit&(1<<i)){
                v += c[i];
                rep(j, m) sum[j] += a[i][j];
            }
        }
        bool ok = true;
        rep(i, m){
            if(sum[i] < x) ok = false;
        }
        if(ok) ans = min(ans, v);
    }
    if(ans == INF) ans = -1;
    cout << ans << el;
    return 0;
}