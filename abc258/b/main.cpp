// B - Number Box
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

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

ll f(int x, int y, int n, const vector<string>& a){
    ll ret = 0;
    rep(i,8){
        vector<int> res;
        int nx = x, ny = y;
        int c = a[nx][ny]-'0';
        res.push_back(c);
        rep(j,n-1){
            nx = (nx+dx[i])%n, ny = (ny+dy[i])%n;
            if(nx < 0) nx += n;
            if(ny < 0) ny += n;
            c = a[nx][ny]-'0';
            res.push_back(c);
        }
        ll num = 0, x10 = 1;
        rrepi(j,res.size(),0){
            num += res[j]*x10;
            x10 *= 10;
        }
        ret = max(ret, num);
    }
    return ret;
}

int main(){
    int n; cin >> n;
    vector<string> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i,n)rep(j,n){
        ans = max(ans, f(i, j, n, a));
    }
    cout << ans << el;
    return 0;
}
