// D - パスタ(Pasta)
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

constexpr int M = 10000;
int exi[105];
ll dp[105][4];

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(k), b(k);
    rep(i,n+1) exi[i] = -1;
    rep(i,k){
        cin >> a[i] >> b[i];
        --a[i]; --b[i];
        exi[a[i]] = b[i];
    }
    if(exi[0] == -1) dp[0][0] = dp[0][1] = dp[0][2] = 1;
    else dp[0][exi[0]] = 1;
    repi(i,1,n){
        int bi = exi[i], bii = exi[i-1];
        if(bi != -1){
            if(i-2 >= 0){
                if(bii != -1){
                    if(bii != bi){
                        dp[i][bi] = dp[i-1][bii];
                    }else{
                        rep(x,3) if(bi != x) dp[i][bi] = ((dp[i][bi]+dp[i-1][x])%M+dp[i-2][x])%M;
                    }
                }else{
                    rep(x,3) if(bi != x) dp[i][bi] = ((dp[i][bi]+dp[i-1][x])%M+dp[i-2][x])%M;
                }
            }else{
                rep(x,3) dp[i][bi] = (dp[i][bi]+dp[i-1][x])%M;
            }
        }else{
            rep(j,3){
                if(i-2 >= 0){
                    if(bii != -1){
                        if(bii != j){
                            dp[i][j] = dp[i-1][bii];
                        }else{
                            rep(x,3) if(bii != x) dp[i][j] = ((dp[i][j]+dp[i-1][x])%M+dp[i-2][x])%M;
                        }
                    }else{
                        rep(x,3) if(j != x) dp[i][j] = ((dp[i][j]+dp[i-1][x])%M+dp[i-2][x])%M;
                    }
                }else{
                    rep(x,3) dp[i][j] = (dp[i][j]+dp[i-1][x])%M;
                }
            }
        }
    }
    int ans = 0;
    rep(i,3) ans = (ans+dp[n-1][i])%M;
    cout << ans << el;
    return 0;
}
