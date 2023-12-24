// A17 - Dungeon 2
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
    vector<int> a(n), b(n);
    repi(i, 1, n) cin >> a[i];
    repi(i, 2, n) cin >> b[i];
    // 動的計画法
    vector<int> dp(n);
    dp[0] = 0, dp[1] = a[1];
    repi(i, 2, n){
        dp[i] = min(a[i]+dp[i-1], b[i]+dp[i-2]);
    }
    // 答えの復元
    int place = n-1;
    vector<int> ans;
    while(true){
        ans.push_back(place+1);
        if(place == 0) break;
        // どこから部屋placeに向かうのが最適か求める
        if(dp[place-1]+a[place] == dp[place]) place--;
        else place -= 2;
    }
    reverse(all(ans));
    cout << ans.size() << el;
    rep(i, ans.size()){
        printf("%d%c", ans[i], i==ans.size()-1?'\n':' ');
    }
    return 0;
}