// D - I Hate Non-Integer Number
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

constexpr int M = 998244353;
// dp[i][j][k][l]: Aのj項まででk個選び、その総和をiで割った余りがlであるような個数(Aの各項についてi(1<=i<=n)の剰余をとる)
int dp[105][105][105][105];

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n+1) dp[i][0][0][0] = 1;
    // NOTE: 解説見ると4次元DPでなく3次元DPで解いている
    rep(i,n){
        rep(j,n){
            int aj = a[j]%(i+1);
            rep(k,n){
                rep(l,n){
                    if(dp[i][j][k][l] >= 1){
                        dp[i][j+1][k][l] = (dp[i][j+1][k][l]+dp[i][j][k][l])%M;
                        int nl = (l+aj)%(i+1);
                        dp[i][j+1][k+1][nl] = (dp[i][j+1][k+1][nl]+dp[i][j][k][l])%M;
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(i,n) ans = (ans+dp[i][n][i+1][0])%M;
    cout << ans << el;
    return 0;
}
