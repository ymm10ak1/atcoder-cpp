// D - aab aba baa
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

ll dp[65][35];

int main(){
    int a, b;
    ll k;
    cin >> a >> b >> k;
    dp[0][0] = 1;
    // nCk = n-1Ck-1+n-1Ckを作る
    rep(i,61){
        rep(j,i+1){
            if(i>0 && j>0 && i==j) dp[i][j] = 1;
            else if(i>0 && j>0) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            else if(i > 0 && j == 0) dp[i][j] = dp[i-1][j];
        }
    }
    string ans = "";
    int absize = a+b;
    rep(i,absize){
        // 仮でi文字目を'a'にして、KとnCkを比較する
        if(a > 0 && b > 0){
            --a;
            if(k <= dp[a+b][min(a,b)]){
                ans += 'a';
            }else{
                // K > nCkのときはkの値を(k-nCk)に更新する
                k -= dp[a+b][min(a,b)];
                ans += 'b';
                --b; ++a;
            }
        }else{
            if(a == 0){
                // 文字'a'が残っていない場合、残りb文字分'b'を足す
                ans += 'b';
            }else if(b == 0){
                // 文字'b'が残っていない場合、残りa文字分'a'を足す
                ans += 'a';
            }
        }
    }
    cout << ans << el;
    return 0;
}