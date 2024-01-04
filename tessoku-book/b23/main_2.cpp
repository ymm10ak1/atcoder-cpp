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
    rep(i, n) rep(j, n){
        cost[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    }
    vector<vector<double>> dp((1<<n), vector<double>(n, INF));
    dp[0][0] = 0;
    rep(i, (1<<n)){
        rep(j, n){
            if(i!=0 && ((i>>j)&1)==0) continue;
            // 都市jからkに訪れたい
            rep(k, n){
                // まだ都市kを訪れていないか
                if(((i>>k)&1) == 0){
                    int ni = i|(1<<k);
                    dp[ni][k] = min(dp[ni][k], dp[i][j]+cost[j][k]);
                }
            }
        }
    }
    printf("%.12f\n", dp[(1<<n)-1][0]);
    return 0;
}