// A - Biscuits
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

// dp[i][j]: i番目までのaで総和jが作れる個数
ll dp[55][5005];

int main(){
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    int sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    dp[0][0] = 1;
    rep(i,n){
        rep(j,sum+1){
            if(dp[i][j] >= 1){
                if(j+a[i] <= sum) dp[i+1][j+a[i]] += dp[i][j];
                dp[i+1][j] += dp[i][j];
            }
        }
    }
    ll ans = 0;
    rep(i,sum+1) if(i%2==p) ans += dp[n][i];
    cout << ans << el;
    return 0;
}