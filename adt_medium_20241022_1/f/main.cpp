// F
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

int h, w, n;

bool check(const vector<string>& s, const string& t, int sx, int sy){
    rep(i,n){
        if(t[i] == 'L') sy--;
        else if(t[i] == 'R') sy++;
        else if(t[i] == 'U') sx--;
        else if(t[i] == 'D') sx++;
        if(sx<0 || sy<0 || sx>=h || sy>=w) return false;
        if(s[sx][sy] == '#') return false;
    }
    return true;
}

int main(){
    string t;
    cin >> h >> w >> n >> t;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#') continue;
            if(check(s,t,i,j)) ++ans;
        }
    }
    cout << ans << el;
    return 0;
}
