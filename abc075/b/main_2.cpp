// B - Minesweeper
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

const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int ma[55][55];

int bombCnt(const vector<string>& s, int i, int j, const int h, const int w){
    int cnt = 0;
    rep(d,8){
        int ni = i+dx[d], nj = j+dy[d];
        if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
        if(s[ni][nj] == '#') ++cnt;
    }
    return cnt;
}

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h){
        rep(j,s[i].size()){
            if(s[i][j] == '.') ma[i][j] = bombCnt(s,i,j,h,w);
            if(s[i][j] == '#') ma[i][j] = -INF;
        }
    }
    rep(i,h){
        rep(j,w){
            if(ma[i][j] == -INF) cout << '#';
            else cout << ma[i][j];
            if(j == w-1) cout << el;
        }
    }
    return 0;
}
