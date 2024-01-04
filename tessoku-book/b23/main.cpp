// B23 - Traveling Salesman Problem
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

int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vector<vector<double>> cost(n, vector<double>(n));
    // 都市iからjにかかるコストを計算
    rep(i, n) rep(j, n){
        cost[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    }
    // NOTE: bitDPについてまだわかっていない
    vector<vector<double>> dp((1<<n), vector<double>(n, INF));
    dp[1][0] = 0;
    rep(s, (1<<n)){
        rep(i, n){
            // 最後に訪れた都市が都市i
            if((s>>i) & 1){
                // 都市iからjに訪れたい
                rep(j, n){
                    // 既に都市jを訪れていないか
                    if(((s>>j)&1) == 0){
                        // 集合sに都市jを加えた集合nsでdpを更新する
                        int ns = s|(1<<j);
                        dp[ns][j] = min(dp[ns][j], dp[s][i]+cost[i][j]);
                    }
                }
            }
        }
    }
    // 最初の都市に戻ってくるコストも加えて最小値を決める
    double ans = INF;
    rep(i, n){
        ans = min(ans, dp[(1<<n)-1][i]+cost[i][0]);
    }
    printf("%.10f\n", ans);
    return 0;
}