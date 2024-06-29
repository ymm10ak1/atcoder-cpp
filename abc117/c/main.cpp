// C - Streamline
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
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i,m) cin >> x[i];
    sort(all(x));
    vector<int> diff;
    rep(i,m-1) diff.push_back(abs(x[i]-x[i+1]));
    sort(rall(diff));
    int ans = 0;
    repi(i,n-1,diff.size()) ans += diff[i];
    cout << ans << el;
    return 0;
}
