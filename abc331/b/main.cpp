#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, s, m, l;
    cin >> n >> s >> m >> l;
    vector<int> dp(n+1,INF);
    dp[0] = 0;
    int a[] = {6, 8, 12};
    int p[] = {s, m, l};
    rep(i,n){
        rep(j,3){
            dp[min(i+a[j],n)] = min(dp[min(i+a[j],n)], dp[i]+p[j]);
        }
    }
    cout << dp[n] << el;
    return 0;
}
