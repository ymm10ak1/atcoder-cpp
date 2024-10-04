// D - Money in Hand
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

// dp[i][j]: i番目まででjを作る際に余る最大のa[i]の個数(jが作れない場合は-1)
int dp[55][10005];

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n+1)rep(j,x+1) dp[i][j] = -INF;
    dp[0][0] = 0;
    rep(i,n){
        rep(j,x+1){
            if(dp[i][j] >= 0) dp[i+1][j] = b[i];
            else if(j<a[i] || dp[i+1][j-a[i]]<=0) dp[i+1][j] = -1;
            else dp[i+1][j] = dp[i+1][j-a[i]]-1;
        }
    }
    if(dp[n][x]>=0) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
