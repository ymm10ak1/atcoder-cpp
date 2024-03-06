// B57 - Calculator
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

int digit_sum(int x){
    int sum = 0;
    while(x > 0){
        sum += x%10;
        x /= 10;
    }
    return sum;
}

int main(){
    int n, k; cin >> n >> k;
    vector<vector<int>> dp(30,vector<int>(n+1));
    // 前計算
    repi(i,1,n+1) dp[0][i] = i-digit_sum(i);
    // 1回目、2回目、4回目、8回目、...とiから各桁の和を引いた値を求めていく
    // 1回目ですべてのiに対して各桁の和を引く計算したあとは、dpの値を利用するだけ(2回以降の操作後にnを超える値は現れないため)
    repi(d,1,30){
        repi(i,1,n+1) dp[d][i] = dp[d-1][dp[d-1][i]];
    }
    repi(i,1,n+1){
        int curPlace = i;
        rrepi(d,30,0){
            if(k & (1<<d)) curPlace = dp[d][curPlace];
        }
        cout << curPlace << el;
    }
    return 0;
}