// A - コンテンスト
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

// dp[i][j]: i番目まででj点を作れるか？
bool dp[105][10005];

int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    dp[0][0] = true;
    rep(i,n){
        rep(j,10001){
            if(!dp[i][j]) continue;
            if(j+p[i] < 10001){
                dp[i+1][j] = dp[i][j];
                dp[i+1][j+p[i]] = dp[i][j];
            }
        }
    }
    int ans = 0;
    rep(i,10001) if(dp[n][i]) ++ans;
    cout << ans << el;
    return 0;
}