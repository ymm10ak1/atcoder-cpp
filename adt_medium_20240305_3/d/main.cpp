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
    int n, m;
    cin >> n >> m;
    vector<string> s(n), t(m);
    rep(i,n) cin >> s[i];
    rep(i,m) cin >> t[i];
    vector<bool> cnt(n, false);
    rep(i,n){
        rep(j,m){
            bool ok = true;
            rep(k,3){
                if(s[i][k+3] != t[j][k]) ok = false;
            }
            if(ok) cnt[i] = true;
        }
    }
    int ans = 0;
    rep(i,n) if(cnt[i]) ++ans;
    cout << ans << el;
    return 0;
}