// C - Strange Bank
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int dp[100005];

void chmin(int& a, int b){
    if(a > b) a = b;
}

int main(){
    int n; cin >> n;
    rep(i,n+1) dp[i] = INF;
    dp[0] = 0;
    repi(i,1,n+1){
        // iを超えないような6の0乗、1乗、2乗、...で確認
        for(int j=1; j<=i; j*=6) chmin(dp[i], dp[i-j]+1);
        // iを超えないような9の0乗、1乗、2乗、...で確認
        for(int j=1; j<=i; j*=9) chmin(dp[i], dp[i-j]+1);
    }
    cout << dp[n] << el;
    return 0;
}
