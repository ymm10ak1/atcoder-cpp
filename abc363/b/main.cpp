// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;
// }}}

int main(){
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    rep(ti,t+1){
        int cnt = 0;
        rep(i,n) if(l[i]+ti >= t) cnt++;
        if(cnt >= p){
            cout << ti << el;
            return 0;
        }
    }
    return 0;
}
