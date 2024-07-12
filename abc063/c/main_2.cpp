// C - Bugged
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

// dp[i][j]: i問目までの得点でj点が作れるか
bool dp[105][10005];

int main(){
    int n; cin >> n;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    int sum = 0;
    rep(i,n) sum += s[i];
    dp[0][0] = true;
    rep(i,n){
        rep(j,sum+1){
            if(!dp[i][j]) continue;
            dp[i+1][j] = dp[i][j];
            if(j+s[i] <= sum) dp[i+1][j+s[i]] = dp[i][j];
        }
    }
    int ans = 0;
    rep(i,sum+1){
        if(!dp[n][i] || i%10==0) continue;
        ans = i;
    }
    cout << ans << el;
    return 0;
}