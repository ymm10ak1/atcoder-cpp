// F
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
    int n;
    ull k;
    cin >> n >> k;
    vector<ull> a(n);
    rep(i,n) cin >> a[i];
    ull ans = 0;
    if(k%2) ans = (k+1)/2*k;
    else ans = k/2*(k+1);
    set<ull> st;
    rep(i,n) if(a[i] <= k) st.insert(a[i]);
    for(ull v : st) ans -= v;
    cout << ans << el;
    return 0;
}
