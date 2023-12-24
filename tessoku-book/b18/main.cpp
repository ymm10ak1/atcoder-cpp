// B18 - Subset Sum with Restoration
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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    // 動的計画法
    vector<vector<bool>> dp(n+1, vector<bool>(s+1));
    dp[0][0] = true;
    repi(i, 1, s+1) dp[0][i] = false;
    repi(i, 1, n+1){
        rep(j, s+1){
            if(j < a[i-1]){
                if(dp[i-1][j]) dp[i][j] = true;
                else dp[i][j] = false;
            }
            if(j >= a[i-1]){
                if(dp[i-1][j] || dp[i-1][j-a[i-1]]) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }
    if(!dp[n][s]){
        cout << -1 << el;
        return 0;
    }
    // 動的計画法の復元
    int cur_n = n, cur_s = s;
    vector<int> ans;
    while(true){
        if(cur_n == 0) break;
        // カード cur_n が選ばれない場合
        if(dp[cur_n-1][cur_s]){
            --cur_n;
        }else{
            ans.push_back(cur_n);
            cur_s -= a[cur_n-1];
            --cur_n;
        }
    }
    cout << ans.size() << el;
    rrepi(i, ans.size(), 0){
        printf("%d%c", ans[i], i==0?'\n':' ');
    }
    return 0;
}