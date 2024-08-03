// I - 部品調達
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

ll dp[1005][1050];

void chmin(ll& a, ll b){
    if(a > b) a = b;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(m);
    vector<int> c(m);
    rep(i,m) cin >> s[i] >> c[i];
    rep(i,m+1)rep(j,(1<<n)) dp[i][j] = LLINF;
    dp[0][0] = 0;
    rep(i,m){
        int sum = 0, slen = s[i].size()-1;
        rep(j,s[i].size()){
            if(s[i][j] == 'Y') sum += (1<<slen);
            slen--;
        }
        rep(j,(1<<n)){
            if(dp[i][j] == LLINF) continue;
            // i番目の部品を選ぶ場合
            chmin(dp[i+1][j|sum], dp[i][j]+c[i]);
            // i番目の部品を選ばない場合
            chmin(dp[i+1][j], dp[i][j]);
        }
    }
    if(dp[m][(1<<n)-1] == LLINF) cout << -1 << el;
    else cout << dp[m][(1<<n)-1] << el;
    return 0;
}