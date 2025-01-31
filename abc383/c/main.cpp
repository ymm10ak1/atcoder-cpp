// 
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

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

int main(){
    int h, w, d;
    cin >> h >> w >> d;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<int>> a(h,vector<int>(w,INF));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    rep(i,h)rep(j,w){
        if(s[i][j] == 'H'){
            a[i][j] = 0;
            q.push({0,i*w+j});
        }
    }
    // NOTE: priority_queueじゃなくてqueueを使っても解ける
    while(!q.empty()){
        pair<int,int> now = q.top(); q.pop();
        rep(i,4){
            int x = now.second/w, y = now.second%w;
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
            if(s[nx][ny] == '#') continue;
            if(a[nx][ny] > now.first+1){
                a[nx][ny] = now.first+1;
                q.push({a[nx][ny],nx*w+ny});
            }
        }
    }
    int ans = 0;
    rep(i,h)rep(j,w){
        if(a[i][j] <= d) ans++;
    }
    cout << ans << el;
    return 0;
}
