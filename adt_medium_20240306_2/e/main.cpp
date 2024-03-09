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

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int h, w;
bool seen[510][510];
pair<int,int> ans;

void dfs(const vector<string>& s, int sx, int sy){
    seen[sx][sy] = true;
    rep(i,8){
        int nx = sx+dx[i], ny = sy+dy[i];
        if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
        if(seen[nx][ny]) continue;
        if(s[nx][ny] == '.'){
            int cnt = 0;
            // 4方向チェック
            rep(j,4){
                int nnx=nx+dx[j], nny=ny+dy[j];
                if(nnx<0 || nnx>=h || nny<0 || nny>=w) continue;
                if(s[nnx][nny] == '#') ++cnt;
            }
            if(cnt >= 2) ans.first = nx+1, ans.second = ny+1;
        }
        dfs(s, nx, ny);
    }
}

int main(){
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int sx = 0, sy = 0;
    rep(i,h){
        rep(j,w){
            if(s[i][j] =='#'){
                sx = i, sy = j;
            }
        }
    }
    dfs(s, sx, sy);
    cout << ans.first << " " << ans.second << el;
    return 0;
}