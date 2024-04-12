// D - Poisonous Full-Course
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

// i番目の料理まででお腹の状態がjのときの美味しさの総和の最大値
ll dp[300005][2];

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    dp[0][0] = dp[0][1] = 0;
    repi(i,1,n+1){
        if(x[i-1]==1){
            // i-1番目のお腹壊した状態の美味しさとi-1番目のお腹を壊してない状態にi番目の美味しさを加えたものの中から大きい方を選ぶ
            dp[i][1] = max(dp[i-1][0]+y[i-1],dp[i-1][1]);
            dp[i][0] = dp[i-1][0];
        }else{
            // i-1番目のお腹を壊してない状態に美味しさを加えたものとi-1番目のお腹を壊した状態に美味しさを加えたものとi-1番目のお腹を壊してない状態の美味しさの中から大きい方を選ぶ
            dp[i][0] = max({dp[i-1][0]+y[i-1],dp[i-1][1]+y[i-1],dp[i-1][0]});
            dp[i][1] = dp[i-1][1];
        }
    }
    cout << max(dp[n][0],dp[n][1]) << el;
    return 0;
}