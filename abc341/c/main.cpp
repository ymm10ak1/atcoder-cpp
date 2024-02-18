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

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main(){
    int h, w, n;
    string t;
    cin >> h >> w >> n >> t;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;
    rep(i,h){
        rep(j,w){
            int sx = i, sy = j, cnt = 0;
            rep(k,t.size()){
                int nx = i, ny = j;
                if(s[sx][sy] == '#') break;
                // 移動
                if(t[k] == 'L'){ nx = sx+dx[0]; ny = sy+dy[0]; }
                else if(t[k] == 'R'){ nx = sx+dx[1]; ny = sy+dy[1]; }
                else if(t[k] == 'U'){ nx = sx+dx[2]; ny = sy+dy[2]; }
                else if(t[k] == 'D'){ nx = sx+dx[3]; ny = sy+dy[3]; }
                // 移動後のチェック
                if(nx<0 || nx>h-1 || ny<0 || ny>w-1) break;
                if(s[nx][ny] == '#') break;
                ++cnt;
                sx = nx, sy = ny;
            }
            if(cnt == t.size()) ++ans;
        }
    }
    cout << ans << el;
    return 0;
}