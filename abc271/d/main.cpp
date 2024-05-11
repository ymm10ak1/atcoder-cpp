// D - Flip and Adjust
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

// dp[i][j]: i枚目のカードまでで総和jが作れるかどうか
bool dp[105][10005];

int main(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    dp[0][0] = true;
    rep(i,n){
        rep(j,s+1){
            if(!dp[i][j]) continue;
            if(j+a[i] <= s) dp[i+1][j+a[i]] = true;
            if(j+b[i] <= s) dp[i+1][j+b[i]] = true;
        }
    }
    if(dp[n][s]){
        cout << "Yes" << el;
    }else{
        cout << "No" << el;
        return 0;
    }
    // 復元処理
    int t = s;
    string ans = "";
    rrepi(i,n+1,1){
        if(t-a[i-1]>=0 && dp[i-1][t-a[i-1]]){
            t -= a[i-1];
            ans += "H";
        }else if(t-b[i-1]>=0 && dp[i-1][t-b[i-1]]){
            t -= b[i-1];
            ans += "T";
        }
    }
    reverse(all(ans));
    cout << ans << el;
    return 0;
}