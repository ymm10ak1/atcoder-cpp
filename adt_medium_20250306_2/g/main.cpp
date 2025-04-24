// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 2e9;
const ll LLINF = 2e18;
// }}}

// dp[i][j] := sのi番目まで見てcapslockの状態がjのときの時間の総和の最短時間
ll dp[300005][2];

template<typename T>
bool chmin(T& a, T b){
    if(a > b){ a = b; return true; }
    return false;
}

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    string s; cin >> s;
    int n = s.size();
    rep(i,n+1)rep(j,2) dp[i][j] = LLINF;
    // if(s[0] == 'a'){
    //     dp[0][0] = x;
    //     dp[0][1] = z+y;
    // }else{
    //     dp[0][0] = y;
    //     dp[0][1] = z+x;
    // }
    // repi(i,1,n){
    //     int nx = x, ny = y;
    //     if(s[i] == 'A') nx = y, ny = x;
    //     dp[i][0] = min({dp[i][0], dp[i-1][0]+nx, dp[i-1][1]+z+nx});
    //     dp[i][1] = min({dp[i][1], dp[i-1][1]+ny, dp[i-1][0]+z+ny});
    // }
    dp[0][0] = 0;
    rep(i,n){
        int a = (s[i]=='A')?1:0;
        rep(j,2){
            rep(k,2){
                ll cost = dp[i][j];
                if(j != k) cost += z;
                if(a == k) cost += x;
                else cost += y;
                chmin(dp[i+1][k], cost);
            }
        }
    }
    cout << min(dp[n][0], dp[n][1]) << el;
    return 0;
}
