// C - (K+1)-th Largest Number
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
    vector<int> b = a;
    sort(all(b));
    b.erase(unique(all(b)),b.end());
    vector<int> ans(n);
    int m = b.size();
    rep(i,n){
        int k = 0;
        int idx = upper_bound(all(b), a[i])-b.begin();
        ans[m-idx]++;
    }
    rep(i,n) cout << ans[i] << el;
    return 0;
}
