// B - Ancestor
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
    int n; cin >> n;
    vector<int> p(n);
    repi(i,1,n){
        cin >> p[i]; --p[i];
    }
    vector<int> dp(n,0);
    dp[0] = 0;
    repi(i,1,n){
        dp[i] = dp[p[i]]+1;
    }
    cout << dp[n-1] << el;
    return 0;
}