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
    int n; cin >> n;
    vector<int> w(n), x(n);
    rep(i,n) cin >> w[i] >> x[i];
    int ans = 0;
    rep(i,24){
        int now = 0;
        rep(j,n){
            int h = (x[j]+i)%24;
            if(h >= 9 && h < 18) now += w[j];
        }
        ans = max(ans, now);
    }
    cout << ans << el;
    return 0;
}
