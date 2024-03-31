// C - Jumping Takahashi
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

bool dp[110][100010];

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    dp[0][0] = true;
    rep(i,n){
        rep(j,x+1){
            if(!dp[i][j]) continue;
            if(j+a[i]<=x) dp[i+1][j+a[i]] = true;
            if(j+b[i]<=x) dp[i+1][j+b[i]] = true;
        }
    }
    if(dp[n][x]) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}