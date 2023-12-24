// A16 - Dungeon 1
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
    vector<int> a(n, 0), b(n, 0);
    repi(i, 1, n) cin >> a[i];
    repi(i, 2, n) cin >> b[i];
    vector<int> dp(n, 0);
    dp[0] = 0, dp[1] = a[1];
    repi(i, 2, n){
        dp[i] = min(dp[i-2]+b[i], dp[i-1]+a[i]);
    }
    cout << dp[n-1] << el;
    return 0;
}