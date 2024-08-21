// 008 - AtCounter（★4）
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

constexpr int M = 1000000007;
string atcoder = "atcoder";
int dp[8][100005];

int main(){
    int n;
    string s;
    cin >> n >> s;
    dp[0][0] = 1;
    rep(i,8){
        repi(j,1,n+1){
            if(i == 0){
                dp[i][j] = dp[i][j-1];
            }else{
                if(s[j-1] == atcoder[i-1]) dp[i][j] = (dp[i][j]+(dp[i-1][j-1]+dp[i][j-1])%M)%M;
                else dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout << dp[7][n] << el;
    return 0;
}
