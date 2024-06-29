// D - Max Multiple
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

// dp[i][j][k]: i項目まででj個選んだときの総和をDで割ったあまりがkであるようなときの総和の最大値
ll dp[105][105][105];

void chmax(ll& a, ll b){
    if(a < b) a = b;
}

int main(){
    int n, k, d;
    cin >> n >> k >> d;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n+1) rep(j,k+1) rep(l,d) dp[i][j][l] = -LLINF;
    dp[0][0][0] = 0;
    rep(i,n){
        rep(j,min(i,k)+1){
            rep(l,d){
                if(dp[i][j][l] >= 0){
                    chmax(dp[i+1][j][l], dp[i][j][l]);
                    if(j+1 <= k) chmax(dp[i+1][j+1][(l+a[i])%d], dp[i][j][l]+a[i]);
                }
            }
        }
    }
    cout << (dp[n][k][0]==-LLINF ? -1 : dp[n][k][0]) << el;
    return 0;
}