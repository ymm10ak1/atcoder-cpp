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

// ヒントありで解けた
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(q);
    rep(i,n) cin >> a[i];
    sort(all(a));
    vector<int> ans;
    rep(i,q){
        int b, k;
        cin >> b >> k;
        int ng = -1, ok = max(abs(a[0]-b),abs(a[n-1]-b))+1;
        while(abs(ok-ng) > 1){
            int mid = (ok+ng)/2;
            int l = lower_bound(all(a), b-mid)-a.begin();
            int r = upper_bound(all(a), b+mid)-a.begin();
            if(r-l >= k) ok = mid;
            else ng = mid;
        }
        ans.push_back(ok);
    }
    for(int x : ans) cout << x << el;
    return 0;
}
