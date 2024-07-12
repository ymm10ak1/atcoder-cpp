// A - 得点
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

const int a[] = {25, 39, 51, 76, 163, 111, 136, 128, 133, 138};
bool dp[11][1100];

int main(){
    int sum = 0;
    rep(i,10) sum += a[i];
    dp[0][0] = true;
    rep(i,10){
        rep(j,1100){
            if(dp[i][j]){
                dp[i+1][j] = dp[i][j];
                if(i==6 && j+58<1100) dp[i+1][j+58] = dp[i][j];
                if(j+a[i] < 1100) dp[i+1][j+a[i]] = dp[i][j];
            }
        }
    }
    rep(i,sum+1){
        if(dp[10][i]) cout << i << el;
    }
    return 0;
}