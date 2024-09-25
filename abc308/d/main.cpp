// D - Snuke Maze
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
using P = pair<int,int>;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
int h, w;

bool bfs(const vector<string>& s){
    queue<P> q;
    set<P> used;
    q.push({0,0});
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        if(used.count({x,y})) continue;
        used.insert({x,y});
        rep(i,4){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
            if(used.count({nx,ny})) continue;
            if(s[x][y]=='s' && s[nx][ny]=='n') q.push({nx,ny});
            else if(s[x][y]=='n' && s[nx][ny]=='u') q.push({nx,ny});
            else if(s[x][y]=='u' && s[nx][ny]=='k') q.push({nx,ny});
            else if(s[x][y]=='k' && s[nx][ny]=='e') q.push({nx,ny});
            else if(s[x][y]=='e' && s[nx][ny]=='s') q.push({nx,ny});
        }
    }
    if(used.count({h-1,w-1})) return true;
    return false;
}


int main(){
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    if(bfs(s)) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
