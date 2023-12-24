// B17 - Frog 1 with Restoration
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
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<int> dp(n);
    dp[0] = 0, dp[1] = abs(h[1]-h[0]);
    repi(i, 2, n) dp[i] = min(abs(h[i]-h[i-1])+dp[i-1], abs(h[i]-h[i-2])+dp[i-2]);
    int p = n-1;
    vector<int> ans;
    while(true){
        ans.push_back(p+1);
        if(p == 0) break;
        if(dp[p-1]+abs(h[p]-h[p-1]) == dp[p]) --p;
        else p -= 2;
    }
    reverse(all(ans));
    cout << ans.size() << el;
    rep(i, ans.size()) printf("%d%c", ans[i], i==ans.size()-1?'\n':' ');
    return 0;
}