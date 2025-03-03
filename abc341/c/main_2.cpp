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

int main(){
    int h, w, n;
    string t;
    cin >> h >> w >> n >> t;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#') continue;
        int x = i, y = j;
        bool ok = true;
        rep(k,n){
            if(t[k] == 'L') y--;
            else if(t[k] == 'R') y++;
            else if(t[k] == 'U') x--;
            else x++;
            if(x<0 || x>=h || y<0 || y>=w){
                ok = false;
                break;
            }
            if(s[x][y] == '#'){
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }
    cout << ans << el;
    return 0;
}
