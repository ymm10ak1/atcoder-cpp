// F
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
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i,h) cin >> g[i];
    int sx = 0, sy = 0;
    vector<vector<bool>> used(h,vector<bool>(w));
    while(1){
        int dx = 0, dy = 0;
        if(g[sx][sy] == 'U') dx = -1;
        else if(g[sx][sy] =='D') dx = 1;
        else if(g[sx][sy] =='L') dy = -1;
        else if(g[sx][sy] =='R') dy = 1;
        if(sx+dx<0 || sy+dy<0 || sx+dx>=h || sy+dy>=w){
            cout << sx+1 << " " << sy+1 << el;
            return 0;
        }
        sx += dx, sy += dy;
        if(used[sx][sy]){
            cout << -1 << el;
            return 0;
        }
        used[sx][sy] = true;
    }
    return 0;
}
