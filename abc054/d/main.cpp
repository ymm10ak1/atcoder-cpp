// D - Mixing Experiment
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

// dp[i][a][b]: i番目の薬品まででタイプAをaグラム、タイプBをbグラムにしたときの最小予算
int dp[45][405][405];

void chmin(int& a, int b){
    if(a > b) a = b;
}

int check(int a, int ma, int mb){
    int res = a*mb/ma;
    if(a*mb%ma == 0) return res;
    return -1;
}

int main(){
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<int> A(n), B(n), C(n);
    rep(i,n) cin >> A[i] >> B[i] >> C[i];
    rep(i,n+1)rep(j,405)rep(k,405) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i,n){
        rep(a,405){
            rep(b,405){
                if(dp[i][a][b] == INF) continue;
                // 薬品を選ばない場合
                chmin(dp[i+1][a][b], dp[i][a][b]);
                // 薬品を選ぶ場合
                if(a+A[i]<405 && b+B[i]<405) chmin(dp[i+1][a+A[i]][b+B[i]],dp[i][a][b]+C[i]);
            }
        }
    }
    int ans = INF;
    repi(a,1,405)repi(b,1,405){
        if(dp[n][a][b] == INF) continue;
        // NOTE: ここの対比チェックはif(a*mb == b*ma)にすればいい
        int x = check(a, ma, mb);
        if(x == b) ans = min(ans, dp[n][a][b]);
    }
    if(ans == INF) cout << -1 << el;
    else cout << ans << el;
    return 0;
}