// C - Traveling
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

int main(){
    int n; cin >> n;
    vector<int> t(n), x(n), y(n);
    rep(i,n) cin >> t[i] >> x[i] >> y[i];
    int cur = 0;
    int sx = 0, sy = 0;
    bool ok = true;
    rep(i,n){
        int nxt = t[i]-cur;
        int nx = abs(x[i]-sx), ny = abs(y[i]-sy);
        // 次の点までの距離がnxtより大きいとたどり着けない
        if(nxt < nx+ny) ok = false;
        // 時刻の偶奇と距離の偶奇が一致するか
        if(nxt%2 != (nx+ny)%2) ok = false;
        cur = t[i];
        sx = x[i], sy = y[i];
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
