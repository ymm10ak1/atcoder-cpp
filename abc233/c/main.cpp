// C - Product
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
    ull x; cin >> x;
    vector<int> l(n);
    vector<vector<int>> a(n);
    int seki = 1;
    rep(i,n){
        cin >> l[i];
        seki *= l[i];
        rep(j,l[i]){
            int ai; cin >> ai;
            a[i].push_back(ai);
        }
    }
    // 解説見ると、DFSでも解けるみたい
    vector<vector<ull>> dp(n+1,vector<ull>(seki,0LL));
    rep(i,seki) dp[0][i] = 1;
    int d = seki;
    repi(i,1,n+1){
        d /= l[i-1];
        int l_idx = 0;
        rep(j,seki){
            if(j>0 && j%d==0){
                l_idx = (l_idx+1)%l[i-1];
                dp[i][j] = a[i-1][l_idx]*dp[i-1][j];
                if(dp[i][j]/a[i-1][l_idx] != dp[i-1][j]) dp[i][j] = 0;
                if(dp[i][j] < 0LL) dp[i][j] = 0;
            }else{
                dp[i][j] = a[i-1][l_idx]*dp[i-1][j];
                if(dp[i][j]/a[i-1][l_idx] != dp[i-1][j]) dp[i][j] = 0;
                if(dp[i][j] < 0LL) dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    rep(i,seki) if(dp[n][i] == x) ++ans;
    cout << ans << el;
    return 0;
}