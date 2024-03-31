// C - Choose Elements
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

bool dp[200010][2];

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    dp[0][0] = dp[0][1] = true;
    // 配列a,bを後ろから見ていたが、前から見ても大丈夫みたい
    rep(i,n-1){
        if(dp[i][0]){
            if(abs(a[n-i-1]-a[n-i-2]) <= k) dp[i+1][0] = true;
            if(abs(a[n-i-1]-b[n-i-2]) <= k) dp[i+1][1] = true;
        }
        if(dp[i][1]){
            if(abs(b[n-i-1]-a[n-i-2]) <= k) dp[i+1][0] = true;
            if(abs(b[n-i-1]-b[n-i-2]) <= k) dp[i+1][1] = true;
        }
    }
    cout << ((dp[n-1][0] || dp[n-1][1]) ? "Yes" : "No") << el;
    return 0;
}