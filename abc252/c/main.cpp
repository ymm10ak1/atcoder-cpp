// C - Slot Strategy
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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans = INF;
    // NOTE: 改良できそう
    rep(i,10){
        vector<int> cnt(10,0);
        int maxn = -1;
        rep(j,n){
            rep(k,s[j].size()){
                if(s[j][k] == i+'0'){
                    maxn = max(maxn, k);
                    ++cnt[k];
                }
            }
        }
        int x10 = -1, maxcnt = 0;
        rep(j,10){
            if(cnt[j] > 1 && maxcnt <= cnt[j]){
                x10 = (cnt[j]-1)*10;
                x10 += j;
                maxcnt = cnt[j];
            }
        }
        if(x10 != -1) ans = min(ans, x10);
        else ans = min(ans, maxn);
    }
    cout << ans << el;
    return 0;
}
