// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 2e9;
const ll LLINF = 2e18;
// }}}

int a[105][105][105];
int s[105][105][105];

int main(){
    int n; cin >> n;
    repi(x,1,n+1)repi(y,1,n+1)repi(z,1,n+1) cin >> a[x][y][z];
    repi(i,1,n+1){
        repi(j,1,n+1)repi(k,1,n+1) s[i][j][k] = s[i][j][k-1]+a[i][j][k];
    }
    repi(i,1,n+1){
        repi(j,1,n+1)repi(k,1,n+1) s[i][k][j] = s[i][k][j]+s[i][k-1][j];
    }
    int q; cin >> q;
    rep(i,q){
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        int ans = 0;
        repi(i,lx,rx+1){
            ans += s[i][ry][rz]-s[i][ly-1][rz]-s[i][ry][lz-1]+s[i][ly-1][lz-1];
        }
        cout << ans << el;
    }
    return 0;
}
