// A24 - LIS
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
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    // 動的計画法
    vector<int> dp(n+1, INF);
    int len = 0;
    rep(i, n){
        int pos = lower_bound(dp.begin()+1, dp.begin()+len+1, a[i]) - dp.begin();
        dp[pos] = a[i];
        if(pos > len) ++len;
    }
    cout << len << el;
    return 0;
}