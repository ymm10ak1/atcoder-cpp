// D - Many Go Round
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

// dp[i][j]: i番目までで休憩所jを訪れるときの最小の周回数
int dp[10005][1000];

template<typename T>
bool chmin(T& a, T b){
    if(a > b){ a = b; return true; }
    return false;
}

int main(){
    int n, m, l, x;
    cin >> n >> m >> l >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n+1)rep(j,m) dp[i][j] = INF;
    dp[0][0] = 1;
    rep(i,n){
        rep(j,m){
            if(dp[i][j] >= 1){
                chmin(dp[i+1][j], dp[i][j]);
                chmin(dp[i+1][(j+a[i])%m], dp[i][j]+(j+a[i])/m);
            }
        }
    }
    if(dp[n][l] <= x) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
