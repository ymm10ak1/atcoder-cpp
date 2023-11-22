// C - Alchemist
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
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    sort(all(v));
    double ans = v[0];
    repi(i, 1, n){
        ans += v[i];
        ans /= 2;
    }
    cout << ans << el;
    return 0;
}