// D
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
const int dx[] = {-1,-1,-1,0,0,1,1,1};
const int dy[] = {-1,0,1,-1,1,-1,0,1};

vector<pair<int,int>> f(const vector<string>& s, int sx, int sy){
    vector<pair<int,int>> res;
    res.emplace_back(0,0);
    rep(i,8){
        vector<pair<int,int>> vp;
        vp.emplace_back(sx,sy);
        int nx = sx+dx[i], ny = sy+dy[i];
        if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
        string t = "";
        t += s[sx][sy];
        rep(j,4){
            if(nx<0 || ny<0 || nx>=h || ny>=w) break;
            t += s[nx][ny];
            vp.emplace_back(nx,ny);
            nx += dx[i], ny += dy[i];
        }
        if((int)t.size()==5 && t=="snuke") return vp;
    }
    return res;
}

int main(){
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h){
        rep(j,w){
            if(s[i][j] == 's'){
                vector<pair<int,int>> ans = f(s, i, j);
                if((int)ans.size() == 5){
                    for(auto [k,v] : ans) cout << k+1 << " " << v+1 << el;
                }
            }
        }
    }
    return 0;
}
