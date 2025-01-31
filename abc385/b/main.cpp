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

int main(){
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--; y--;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    string t; cin >> t;
    vector<vector<bool>> check(h,vector<bool>(w));
    int c = 0;
    rep(i,t.size()){
        if(t[i] == 'U'){
            if(x-1 < 0) continue;
            if(s[x-1][y] == '#') continue;
            x--;
        }
        if(t[i] == 'D'){
            if(x+1 >= h) continue;
            if(s[x+1][y] == '#') continue;
            x++;
        }
        if(t[i] == 'L'){
            if(y-1 < 0) continue;
            if(s[x][y-1] == '#') continue;
            y--;
        }
        if(t[i] == 'R'){
            if(y+1 >= w) continue;
            if(s[x][y+1] == '#') continue;
            y++;
        }
        if(s[x][y]=='@' && !check[x][y]){
            c++;
            check[x][y] = true;
        }
    }
    printf("%d %d %d\n", x+1, y+1, c);
    return 0;
}
