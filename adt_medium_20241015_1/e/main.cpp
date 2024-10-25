// E
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
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s; cin >> s;
    vector<int> x(m), y(m);
    rep(i,m) cin >> x[i] >> y[i];
    map<pair<int,int>,bool> mp;
    rep(i,m) mp[{x[i],y[i]}] = true;
    int sx = 0, sy = 0;
    rep(i,n){
        h--;
        if(s[i] == 'R') sx++;
        else if(s[i] == 'L') sx--;
        else if(s[i] == 'U') sy++;
        else if(s[i] == 'D') sy--;
        if(h < 0){
            cout << "No" << el;
            return 0;
        }
        if(mp[{sx,sy}] && h<k){
            h = k;
            mp[{sx,sy}] = false;
        }
    }
    cout << "Yes" << el;
    return 0;
}
