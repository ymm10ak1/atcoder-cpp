// C - Sensors
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

int h, w;
const int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

void dfs(const vector<string>& s, vector<vector<bool>>& used, int x, int y){
    rep(i,9){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
        if(s[nx][ny] == '.') continue;
        if(used[nx][ny]) continue;
        used[nx][ny] = true;
        dfs(s, used, nx, ny);
    }
}

int main(){
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<bool>> used(h,vector<bool>(w,false));
    int ans = 0;
    rep(i,h)rep(j,w){
        if(s[i][j]=='#' && !used[i][j]){
            dfs(s, used, i, j);
            ++ans;
        }
    }
    cout << ans << el;
    return 0;
}
