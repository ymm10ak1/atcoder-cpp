// C - All Green
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

// iまでの問題でj問を解いたときの最高得点
ll dp[12][1005];

int main(){
    int d;
    ll g;
    cin >> d >> g;
    int pSum = 0;
    vector<int> p(d), c(d);
    rep(i,d){
        cin >> p[i] >> c[i];
        pSum += p[i];
    }
    // dp全体を-1で初期化してdp[0][0]を0にして、dp[i][j]が0以上のときにスコアの計算をすればよさそう
    dp[0][0] = 0;
    rep(i,d){
        rep(j,pSum+1){
            if(j==0 || dp[i][j]>0){
                rep(k,p[i]){
                    ll score = (100*(i+1))*(k+1);
                    score = score+(k==p[i]-1?c[i]:0);
                    if(j+k+1<=pSum) dp[i+1][j+k+1] = max(dp[i+1][j+k+1],dp[i][j]+score);
                }
            }
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
        }
    }
    rep(i,pSum+1){
        if(dp[d][i]>=g){
            cout << i << el;
            return 0;
        }
    }
    return 0;
}