// A - Irreversible operation
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

ll dp[200010];

int main(){
    string s; cin >> s;
    int b_cnt = (s[0]=='B') ? 1 : 0;
    dp[0] = 0;
    repi(i,1,s.size()){
        if(s[i] == 'W'){
            dp[i] = dp[i-1]+b_cnt;
        }else{
            ++b_cnt;
            dp[i] = dp[i-1];
        }
    }
    cout << dp[(int)s.size()-1] << el;
    return 0;
}