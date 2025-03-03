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
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    int n; cin >> n;
    map<P,int> mp;
    rep(i,n){
        int r, c, e;
        cin >> r >> c >> e;
        mp[{r-1,c-1}] = e;
    }
    P s = {0,0}, g = {0,0};
    rep(i,h)rep(j,w){
        if(a[i][j] == 'S') s = {i,j};
        if(a[i][j] == 'T') g = {i,j};
    }
    using PP = pair<int,pair<int,int>>;
    priority_queue<PP> q;
    vector<int> dist(h*w,-INF);
    q.emplace(mp[s], s);
    if(mp[s] > 0) mp.erase(s);
    dist[s.first*w+s.second] = mp[s];
    while(!q.empty()){
        auto [cur, p] = q.top(); q.pop();
        auto [x, y] = p;
        rep(i,4){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
            if(a[nx][ny] == '#') continue;
            if(mp[{nx,ny}]>0 && cur>0 && cur-1<mp[{nx,ny}] && dist[nx*w+ny]<mp[{nx,ny}]){
                dist[nx*w+ny] = mp[{nx,ny}];
                q.emplace(mp[{nx,ny}], P(nx,ny));
                mp.erase({nx,ny});
            }
            if(cur>0 && dist[nx*w+ny]<cur-1){
                dist[nx*w+ny] = cur-1;
                q.emplace(cur-1, P(nx,ny));
            }
        }
    }
    if(dist[g.first*w+g.second] >= 0) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
