// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;
// }}}

int dp[200005][2];

template<typename T>
bool chmax(T& a, T b){
    if(a < b){ a = b; return true; }
    return false;
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    string ws(n,'.');
    rep(i,n){
        if(s[i] == 'R') ws[i] = 'P';
        if(s[i] == 'P') ws[i] = 'S';
        if(s[i] == 'S') ws[i] = 'R';
    }
    dp[0][0] = 0;
    dp[0][1] = 1;
    rep(i,n-1){
        if(ws[i] != ws[i+1]) chmax(dp[i+1][1], dp[i][1]+1);
        if(s[i] != ws[i+1]) chmax(dp[i+1][1], dp[i][0]+1);
        if(ws[i] != s[i+1]) chmax(dp[i+1][0], dp[i][1]);
        if(s[i] != s[i+1]) chmax(dp[i+1][0], dp[i][0]);
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << el;
    return 0;
}
