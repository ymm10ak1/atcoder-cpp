// C - Changing Jewels
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

// dp:赤の宝石の個数, ep:青の宝石の個数
ll dp[11], ep[11];

// NOTE: dp:レベルiの赤い宝石を1個持っている状態からはじめて、入手できるレベル1の青い宝石の個数
// ep:レベルiの青い宝石を1個持っている状態からはじめて、入手できるレベル1の青い宝石の個数
// と解説では定義していた。
int main(){
    int n, x, y;
    cin >> n >> x >> y;
    // 初期値
    dp[1] = 1;
    ep[1] =  n==1 ? 0 : dp[1]*x;
    repi(i,2,n+1){
        // 赤の宝石の更新
        dp[i] = ep[i-1]+dp[i-1];
        // 青の宝石の更新 レベル1のときは赤の宝石からは貰わない
        if(i < n) ep[i] = ep[i-1]*y+dp[i]*x;
        else ep[i] = ep[i-1]*y;
    }
    // 青の宝石の個数を出力
    cout << ep[n] << el;
    return 0;
}