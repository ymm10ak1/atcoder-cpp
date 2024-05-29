// D - Lamp
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

int h, w;
int dp[2005][2005], ep[2005][2005];

int cnt(int x, int y){
    return dp[x+1][y+1]+ep[x+1][y+1];
}

int main(){
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    repi(i,1,h+1) repi(j,1,w+1){
        if(s[i-1][j-1] == '.'){
            dp[i][j] = dp[i][j-1]+1;
            ep[i][j] = ep[i-1][j]+1;
        }
    }
    repi(i,1,h+1) rrepi(j,w+1,1){
        if(dp[i][j] ==  0) continue;
        if(dp[i][j-1] > 0) dp[i][j-1] = dp[i][j];
    }
    repi(i,1,w+1) rrepi(j,h+1,1){
        if(ep[j][i] == 0) continue;
        if(ep[j-1][i] > 0) ep[j-1][i] = ep[j][i];
    }
    int ans = 0;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '.') ans = max(ans, cnt(i,j)-1);
        }
    }
    cout << ans << el;
    return 0;
}
