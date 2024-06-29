// D - Prediction and Restriction
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

int main(){
    int n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    int ans = 0;
    rep(i,k){
        // j mod kの文字列を取り出す
        string tt = "";
        for(int j=i; j<n; j+=k) tt += t[j];
        vector<int> dp((int)tt.size()+1, 0);
        vector<char> ep((int)tt.size()+1);
        ep[0] = 'x';
        rep(j,tt.size()){
            if(tt[j] == 'r'){
                if(ep[j] == 'p'){
                    ep[j+1] = 'x';
                    dp[j+1] = dp[j];
                }else{
                    ep[j+1] = 'p';
                    dp[j+1] = dp[j]+p;
                }
            }else if(tt[j] == 's'){
                if(ep[j] == 'r'){
                    ep[j+1] = 'x';
                    dp[j+1] = dp[j];
                }else{
                    ep[j+1] = 'r';
                    dp[j+1] = dp[j]+r;
                }
            }else if(tt[j] == 'p'){
                if(ep[j] == 's'){
                    ep[j+1] = 'x';
                    dp[j+1] = dp[j];
                }else{
                    ep[j+1] = 's';
                    dp[j+1] = dp[j]+s;
                }
            }
        }
        ans += dp[(int)tt.size()];
    }
    cout << ans << el;
    return 0;
}
