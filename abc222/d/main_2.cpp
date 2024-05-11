// D - Between Two Arrays
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

const int MOD = 998244353;
// dp[i][j]: i番目のAi~Biでjがciのときの個数
int dp[3005][3005];

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    // 解説では最初の項(a[0],b[0])の処理は、dp[0][0] = 1にして遷移部分で累積和取るようにしていた
    // そうすれば初期化の部分でfor回す必要がなくもっと簡単にかける
    repi(i,a[0],b[0]+1) dp[0][i] = 1;
    repi(i,1,n){
        // 累積和
        rep(j,b[i]) dp[i-1][j+1] = (dp[i-1][j]+dp[i-1][j+1])%MOD;
        repi(j,a[i],b[i]+1) dp[i][j] = dp[i-1][j];
    }
    int ans = 0;
    repi(i,a[n-1],b[n-1]+1) ans = (ans+dp[n-1][i])%MOD;
    cout << ans << el;
    return 0;
}