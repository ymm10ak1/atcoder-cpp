// G - グリッド金移動
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

const int dx[] = {1, 0, -1, 1, -1, 0};
const int dy[] = {1, 1, 1, 0, 0, -1};
const int max_size = 405;

vector<vector<int>> bfs(map<pair<int, int>, bool>& mp){
    queue<pair<int, int>> q;
    vector<vector<int>> dist(max_size, vector<int>(max_size, -1));
    q.push({201, 201});
    dist[201][201] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second; q.pop();
        rep(dir, 6){
            int nx = x+dx[dir], ny = y+dy[dir];
            // 配列外参照しないようにする
            if(nx<0 || nx>=404 || ny<0 || ny>=404) continue;
            // 壁には進めない
            if(mp[{nx, ny}]) continue;
            // 探索済みの場合はスキップする
            if(dist[nx][ny] != -1) continue;
            // キューの追加と距離の更新
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y]+1;
        }
    }
    return dist;
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> xi(n), yi(n);
    rep(i, n){
        cin >> xi[i] >> yi[i];
        xi[i] += 201;
        yi[i] += 201;
    }
    map<pair<int, int>, bool> mp;
    rep(i, n) mp[{xi[i], yi[i]}] = true;
    vector<vector<int>> dist = bfs(mp);
    int ans = dist[x+201][y+201];
    cout << ans << el;
    return 0;
}