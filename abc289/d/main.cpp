// D - Step UP Robot
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

// 0:登ってない, 1:登った, 2:モチが設置されている
int dp[100005];

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int m; cin >> m;
    vector<int> b(m);
    rep(i,m){
        cin >> b[i];
        dp[b[i]] = 2;
    }
    int x; cin >> x;
    dp[0] = 1;
    rep(i,x+1){
        if(dp[i]==0 || dp[i]==2) continue;
        rep(j,n){
            if(i+a[j] <= x){
                if(dp[i+a[j]] == 2) continue;
                dp[i+a[j]] = 1;
            }
        }
    }
    cout << (dp[x]==1?"Yes":"No") << el;
    return 0;
}