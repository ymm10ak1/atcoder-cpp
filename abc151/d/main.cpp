// D - Maze Master
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

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

vector<vector<int>> bfs(const vector<string> &s, const int h, const int w, int sx, int sy){
    queue<pair<int, int>> q;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[sx][sy] = 0;
    q.push({sx, sy});
    while(!q.empty()){
        pair<int, int> p = q.front();
        int x = p.first, y = p.second;
        q.pop();
        rep(i, 4){
            int x2 = x+dx[i], y2 = y+dy[i];
            // 配列外参照(迷路の外に出ること)はダメ
            if(x2<0 || x2>=h || y2<0 || y2>=w) continue;
            // 壁のマスに移動できない
            if(s[x2][y2] == '#') continue;
            // すでに訪れた場合はスキップ
            if(dist[x2][y2] != -1) continue;
            q.push({x2, y2});
            dist[x2][y2] = dist[x][y]+1;
        }
    }
    return dist;
}

int max_dist(const vector<vector<int>> &dist){
    int max_d = 0;
    rep(i, dist.size()){
        rep(j, dist[i].size()){
            max_d = max(max_d, dist[i][j]);
        }
    }
    return max_d;
}

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int ans = 0;
    int cnt = 0;;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '.'){
                vector<vector<int>> dist = bfs(s, h, w, i, j);
                ans = max(ans, max_dist(dist));
            }
        }
    }
    cout << ans << el;
    return 0;
}