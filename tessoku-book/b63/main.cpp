// B63 - 幅優先探索
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

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int main(){
    int r, c, sy, sx, gy, gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    --sy; --sx; --gy; --gx;
    vector<string> s(r);
    rep(i,r) cin >> s[i];
    vector<int> dist(r*c+1, -1);
    queue<int> q;
    // ヒントより頂点(i,j)を1つの整数(i*C+j)で表す
    dist[sy*c+sx] = 0;
    q.push(sy*c+sx);
    while(!q.empty()){
        int v = q.front(); q.pop();
        int x = v/c, y = v%c;
        rep(i,4){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
            if(s[nx][ny] == '#') continue;
            int nv = nx*c+ny;
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v]+1;
            q.push(nv);
        }
    }
    cout << dist[gy*c+gx] << el;;
    return 0;
}