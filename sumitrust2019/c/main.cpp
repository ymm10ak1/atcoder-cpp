// C - 100 to 500
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
    int x; cin >> x;
    vector<bool> dp(x+1,false);
    dp[0] = true;
    // 解説を見るとDPの処理はもっと簡単に実装できるみたい
    rep(a,1000){
        vector<bool> p = dp;
        rep(i,x+1){
            if(dp[i]){
                p[i] = dp[i];
                rep(j,6){
                    if(i+100+j > x) continue;
                    p[i+100+j] = dp[i];
                }
            }
        }
        swap(dp,p);
        if(dp[x]){
            cout << 1 << el;
            return 0;
        }
    }
    cout << (dp[x] ? 1 : 0) << el;
    return 0;
}