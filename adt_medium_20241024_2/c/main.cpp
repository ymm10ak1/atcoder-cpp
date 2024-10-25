// C
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
    vector<int> w(n), x(n);
    rep(i,n) cin >> w[i] >> x[i];
    int ans = 0;
    rep(i,24){
        int v = 0;
        rep(j,n){
            int t1 = (i+x[j])%24;
            int t2 = (i+1+x[j])%24;
            if(t1>=9 && t2<=18 && t2-t1==1) v += w[j];
        }
        ans = max(ans, v);
    }
    cout << ans << el;
    return 0;
}
