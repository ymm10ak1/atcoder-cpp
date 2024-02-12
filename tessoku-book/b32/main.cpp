// B32 - Game 5
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
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    rep(i, k) cin >> a[i];
    // dp[i]がtrueは勝ちの状態、falseは負けの状態
    vector<bool> dp(n+1, false);
    rep(i, n+1){
        rep(j, k){
            if(i>=a[j] && dp[i-a[j]]==false) dp[i] = true;
        }
    }
    if(dp[n]) cout << "First" << el;
    else cout << "Second" << el;
    return 0;
}