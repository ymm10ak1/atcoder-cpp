// C - Switches
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
    int n, m;
    cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> s;
    rep(i, m){
        cin >> k[i];
        vector<int> ss;
        rep(j, k[i]){
            int si;
            cin >> si;
            ss.push_back(si);
        }
        s.push_back(ss);
    }
    vector<int> p(m);
    rep(i, m) cin >> p[i];
    int ans = 0;
    rep(bit, (1<<n)){
        vector<int> cnt(m);
        rep(i, n){
            if(bit&(1<<i)){
                rep(j, m){
                    rep(k, s[j].size()){
                        if(s[j][k] == i+1) cnt[j]++;
                    }
                }
            }
        }
        bool ok = true;
        rep(i, m){
            if(cnt[i]%2 != p[i]) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans << el;
    return 0;
}