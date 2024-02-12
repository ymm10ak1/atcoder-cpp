// A38 - Black Company 1
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

int main(){
    int d, n;
    cin >> d >> n;
    vector<int> l(n), r(n), h(n);
    rep(i, n) cin >> l[i] >> r[i] >> h[i];
    vector<int> r_time(d+1, 24);
    rep(i, n){
        repi(j, l[i], r[i]+1) r_time[j] = min(r_time[j], h[i]);
    }
    int sum = 0;
    repi(i, 1, d+1) sum += r_time[i];
    cout << sum << el;
    return 0;
}