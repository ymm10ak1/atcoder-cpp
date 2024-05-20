// A - Range Flip Find Route
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

int dp[105][105];
int ma[105][105];

void rev(const vector<string>& s, int i, int j, const int h, const int w){
    int ni = i, nj = j;
    // 右方向に黒色が何マス続いているか
    while(nj < w){
        if(s[i][nj] == '#') ++nj;
        else break;
    }
    // 下方向に黒色が何マス続いているか
    while(ni < h){
        if(s[ni][j] == '#') ++ni;
        else break;
    }
    repi(r,i,ni) repi(c,j,nj) ma[r][c] = 1;
}

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h){
        rep(j,w){
            if(i>0 && j>0){
                if(s[i][j] == '.'){
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                }else if(s[i][j] == '#'){
                    if(ma[i][j] == 0){
                        rev(s, i, j, h, w);
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
                    }else{
                        if(s[i-1][j]=='#' && s[i][j-1]=='#') dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                        else if(s[i-1][j] == '#') dp[i][j] = dp[i-1][j];
                        else if(s[i][j-1] == '#') dp[i][j] = dp[i][j-1];
                    }
                }
            }else if(i>0 && j==0){
                if(s[i][j] == '.'){
                    dp[i][j] = dp[i-1][j];
                }else if(s[i][j] == '#'){
                    if(ma[i][j] == 0){
                        rev(s, i, j, h, w);
                        dp[i][j] = dp[i-1][j]+1;
                    }else{
                        if(s[i-1][j] == '#') dp[i][j] = dp[i-1][j];
                    }
                }
            }else if(i==0 && j>0){
                if(s[i][j] == '.'){
                    dp[i][j] = dp[i][j-1];
                }else if(s[i][j] == '#'){
                    if(ma[i][j] == 0){
                        rev(s, i, j, h, w);
                        dp[i][j] = dp[i][j-1]+1;
                    }else{
                        if(s[i][j-1] == '#') dp[i][j] = dp[i][j-1];
                    }
                }
            }else{
                if(s[i][j] == '#'){
                    if(ma[i][j] == 0){
                        rev(s, i, j, h, w);
                        dp[i][j] = 1;
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }
    }
    cout << dp[h-1][w-1] << el;
    return 0;
}
