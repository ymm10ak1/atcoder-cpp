#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

const int n = 10;
// dp[i][j]: 上からi桁目をjとしたときの条件を満たす個数
ll dp[n][n];

int main(){
    ll K; cin >> K;
    rep(i,n) dp[0][i] = 1;
    rep(i,n-1){
        rep(j,n-1){
            if(dp[i][j] == 0) continue;
            repi(k,j+1,n) dp[i+1][k] += dp[i][j];
        }
    }
    string ans = "";
    rep(i,n)rep(j,n){
        if(i==0 && j==0) continue;
        if(K <= dp[i][j]){
            ans += j+'0';
            if(i == 0){
                cout << ans << el;
                return 0;
            }
            rrep(k,i,0){
                rep(l,n){
                    if(K <= dp[k][l]){
                        ans += l+'0';
                        if(k == 0){
                            cout << ans << el;
                            return 0;
                        }
                        break;
                    }
                    K -= dp[k][l];
                }
            }
        }
        K -= dp[i][j];
    }
    return 0;
}
