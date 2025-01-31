// D - DISCO!
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

const string DISCO = "DISCO";
const ll M = 1LL<<32;

// BUG: WAとTLEのため改善しないといけない
// NOTE: 今の実力では解けないため後回し
int main(){
    string s;
    int q;
    cin >> s >> q;
    int n = s.size();
    vector<vector<ll>> dp(n+1,vector<ll>(6,0));
    dp[0][0] = 1;
    repi(i,1,n+1){
        rep(j,6){
            dp[i][j] = (dp[i][j]+dp[i-1][j])%M;
            if(j>0 && s[i-1]==DISCO[j-1]) dp[i][j] = (dp[i][j]+dp[i-1][j-1])%M;
        }
    }
    rep(i,q){
        int l, r;
        cin >> l >> r;
        // 以下の解法はWAとTLE
        int cnt_i = 0, cnt_s = 0, cnt_c = 0, cnt_o = 0;
        repi(j,l-1,r){
            if(s[j] == 'I') cnt_i++;
            if(s[j] == 'S') cnt_s++;
            if(s[j] == 'C') cnt_c++;
            if(s[j] == 'O') cnt_o++;
        }
        ll sum = dp[r][5];
        sum -= dp[l-1][1]*cnt_i*cnt_s*cnt_c*cnt_o;
        sum -= dp[l-1][2]*cnt_s*cnt_c*cnt_o;
        sum -= dp[l-1][3]*cnt_c*cnt_o;
        sum -= dp[l-1][4]*cnt_o;
        sum -= dp[l-1][5];
        if(sum < 0) sum = 0;
        cout << sum << el;
    }
    return 0;
}
