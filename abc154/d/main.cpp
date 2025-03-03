// D - Dice in Line
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
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    vector<int> s(n+1);
    rep(i,n) s[i+1] = s[i]+p[i]+1;
    int mx = 0;
    repi(i,k,n+1) mx = max(mx, s[i]-s[i-k]);
    double ans = (double)mx/2;
    printf("%.12f\n", ans);
    return 0;
}
