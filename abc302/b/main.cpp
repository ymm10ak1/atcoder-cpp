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

int h, w;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

vector<pair<int,int>> find_s(const vector<string>& s, int x, int y){
    vector<pair<int,int>> res;
    rep(i,8){
        vector<pair<int,int>> pa;
        pa.emplace_back(x,y);
        string t = "";
        t += s[x][y];
        int nx = x, ny = y;
        rep(j,4){
            nx += dx[i], ny += dy[i];
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
            t += s[nx][ny];
            pa.emplace_back(nx,ny);
        }
        if(t == "snuke") return pa;
    }
    return res;
}

int main(){
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h)rep(j,w){
        if(s[i][j] == 's'){
            auto ans = find_s(s, i, j);
            if(ans.size() == 5){
                for(auto p : ans) cout << p.first+1 << " " << p.second+1 << el;
            }
        }
    }
    return 0;
}
