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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    queue<pair<int,int>> q;
    // NOTE: 解説放送見てここの処理がないとs[0][0]がsじゃないのに答えがYesになる
    // 間違ってYesを出してしまうケース
    // H=2 W=3
    // nuk
    // xxe
    if(s[0][0] == 's') q.emplace(0,0);
    vector<vector<bool>> visited(h,vector<bool>(w));
    while(q.size()){
        auto now = q.front(); q.pop();
        if(visited[now.first][now.second]) continue;
        visited[now.first][now.second] = true;
        char c = s[now.first][now.second];
        rep(i,4){
            int nx = now.first+dx[i], ny = now.second+dy[i];
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;;
            if(visited[nx][ny]) continue;
            bool ok = false;
            if(c=='s' && s[nx][ny]=='n') ok = true;
            if(c=='n' && s[nx][ny]=='u') ok = true;
            if(c=='u' && s[nx][ny]=='k') ok = true;
            if(c=='k' && s[nx][ny]=='e') ok = true;
            if(c=='e' && s[nx][ny]=='s') ok = true;
            if(!ok) continue;
            if(ok) q.emplace(nx,ny);
        }
    }
    if(visited[h-1][w-1]) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
