// C Chinese Restaurant
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
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    vector<int> cnt(n);
    rep(i,n){
        int p3[3];
        int d = -1;
        rep(j,3){
            p3[j] = (p[i]+d+j)%n;
            if(p3[j] < 0) p3[j] += n;
            int ka = (i-p3[j])%n;
            if(ka < 0) ka += n;
            cnt[ka]++;
        }
    }
    int ans = 0;
    rep(i,n) ans = max(ans, cnt[i]);
    cout << ans << el;
    return 0;
}
