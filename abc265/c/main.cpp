// C - Belt Conveyor
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
    vector<vector<bool>> used(h,vector<bool>(w));
    int i = 0, j = 0;
    used[i][j] = true;
    int dx = 0, dy = 0;
    while(1){
        if(g[i][j] == 'U') dx = -1, dy = 0;
        else if(g[i][j] == 'D') dx = 1, dy = 0;
        else if(g[i][j] == 'L') dy = -1, dx = 0;
        else if(g[i][j] == 'R') dy = 1, dx = 0;
        if(i+dx<0 || j+dy<0 || i+dx>=h || j+dy>= w){
            cout << i+1 << " " << j+1 << el;
            return 0;
        }
        i += dx, j += dy;
        if(used[i][j]){
            cout << -1 << el;
            return 0;
        }
        used[i][j] = true;
    }
    return 0;
}
