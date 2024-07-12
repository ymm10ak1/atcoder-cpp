// 052 - Dice Product（★3）
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

constexpr int M = 1e9+7;

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(6));
    rep(i,n) rep(j,6) cin >> a[i][j];
    ll ans = 1;
    rep(i,n){
        int sum = 0;
        // 各a[i]の総和を掛けたものが答え
        rep(j,6) sum += a[i][j];
        ans = (ans*sum)%M;
    }
    cout << ans << el;
    return 0;
}