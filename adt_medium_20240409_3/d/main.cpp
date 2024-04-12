// 
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m,vector<int>(n));
    rep(i,m) rep(j,n) cin >> a[i][j];
    vector<vector<bool>> tonari(n+1,vector<bool>(n+1));
    rep(i,m){
        rep(j,n-1){
            tonari[a[i][j]][a[i][j+1]] = true;
            tonari[a[i][j+1]][a[i][j]] = true;
        }
    }
    int ans = 0;
    repi(i,1,n+1) repi(j,1,n+1){
        if(i == j) continue;
        if(!tonari[i][j]) ++ans;
    }
    ans /= 2;
    cout << ans << el;
    return 0;
}