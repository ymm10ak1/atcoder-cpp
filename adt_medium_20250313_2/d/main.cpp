// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 2e9;
const ll LLINF = 2e18;
// }}}

int main(){
    int n; cin >> n;
    vector<int> a(4*n-1);
    rep(i,4*n-1) cin >> a[i];
    vector<int> cnt(n);
    rep(i,4*n-1) cnt[a[i]-1]++;
    rep(i,n) if(cnt[i] == 3) {
        cout << i+1 << el;
        return 0;
    }
    return 0;
}
