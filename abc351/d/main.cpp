#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h)rep(j,w) if(s[i][j] == '#'){
        rep(k,4){
            int nx = i+dx[k], ny = j+dy[k];
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
            if(s[nx][ny] == '#') continue;
            s[nx][ny] = 'x';
        }
    }
    vector<bool> visited(h*w);
    int ans = 1;
    rep(i,h)rep(j,w){
        if(s[i][j]=='.' && !visited[i*w+j]){
            int cnt = 0;
            queue<P> q; q.emplace(i,j);
            set<P> xs;
            while(!q.empty()){
                auto [x, y] = q.front(); q.pop();
                if(visited[x*w+y]) continue;
                visited[x*w+y] = true;
                cnt++;
                rep(k,4){
                    int nx = x+dx[k], ny = y+dy[k];
                    if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                    if(s[nx][ny] == '#') continue;
                    if(visited[nx*w+ny]) continue;
                    if(s[nx][ny] == 'x'){
                        if(xs.count({nx,ny}) == 0){
                            cnt++;
                            xs.emplace(nx,ny);
                        }
                        continue;
                    }
                    q.emplace(nx,ny);
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << el;
    return 0;
}
