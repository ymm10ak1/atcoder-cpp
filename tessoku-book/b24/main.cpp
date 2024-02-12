// B24 - Many Boxes
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

// NOTE: WAになったので修正中
int main(){
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    rep(i, n) cin >> p[i].first >> p[i].second;
    sort(all(p));
    int l[n+1], check[n+1];
    rep(i, n+1){
        l[i] = INF; check[i] = 0;
    }
    l[0] = 0;
    int len = 0;
    // NOTE: xの値のチェックを入れる必要がある
    repi(i, 1, n+1){
        int pos = lower_bound(l+1, l+len+1, p[i-1].second) - l;
        // TODO: 各長さについてどのxiが最後に更新したかを配列checkで記録していくように実装する(まだ実装できていない)
        if(check[pos-1] != p[i-1].first){
            check[pos] = p[i-1].first;
            l[pos] = p[i-1].second;
        }
        if(pos > len) len += 1;
    }
    cout << len << el;
    return 0;
}