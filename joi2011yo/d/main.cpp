// D - 1年生(A First Grader)
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

ll dp[105][21];

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    dp[0][0] = 1;
    rep(i,n-1){
        rep(j,21){
            if(dp[i][j] >= 1){
                if(j-a[i] >= 0) dp[i+1][j-a[i]] += dp[i][j];
                // 1項目が0のときは2回連続で足さないようにする
                if(i==0 && a[i]==0) continue;
                if(j+a[i] <= 20) dp[i+1][j+a[i]] += dp[i][j];
            }
        }
    }
    cout << dp[n-1][a[n-1]] << el;
    return 0;
}
