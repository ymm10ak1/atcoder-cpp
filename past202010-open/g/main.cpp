// G - 村整備
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

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

vector<vector<int>> bfs(const vector<string>& s, const int n, const int m, pair<int, int> st){
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    q.push(st);
    dist[st.first][st.second] = 0;
    while(!q.empty()){
        int x = q.front().first; 
        int y = q.front().second; q.pop();
        rep(dir, 4){
            int nx = x+dx[dir], ny = y+dy[dir];
            // 配列外参照しないようにする
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            // 次のマスが壁の場合は進めない
            if(s[nx][ny] == '#') continue;
            // 探索済みはスキップ
            if(dist[nx][ny] != -1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y]+1;
        }
    }
    return dist;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    map<pair<int, int>, bool> mp;
    int ans = 0;
    rep(i, n){
        rep(j, m){
            if(mp[{i, j}]) continue;
            if(s[i][j] == '#'){
                s[i][j] = '.';
                mp[{i, j}] = true;
                vector<vector<int>> dist = bfs(s, n, m, {i, j});
                bool ok = true;
                rep(k, n) rep(l, m){
                    if(s[k][l] == '#') continue;
                    if(dist[k][l] == -1) ok = false;
                }
                if(ok) ++ans;
                s[i][j] = '#';
            }
        }
    }
    cout << ans << el;
    return 0;
}