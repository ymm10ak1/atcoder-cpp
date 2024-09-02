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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b;
    rep(i,n-1) b.push_back(a[i+1] - a[i]);
    int m = b.size();
    int r = 0;
    ll ans = 0;
    rep(l,m){
        int cnt = 0;
        while(r<m && b[l]==b[r]) ++r;
        ans += r-l;
    }
    ans += n;
    cout << ans << el;
    return 0;
}
