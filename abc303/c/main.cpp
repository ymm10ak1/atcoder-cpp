// C - Dash
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
    vector<pair<int,int>> xy(m);
    rep(i,m) cin >> xy[i].first >> xy[i].second;
    map<pair<int,int>, int> mp;
    rep(i,m) mp[xy[i]]++;
    int x = 0, y = 0;
    rep(i,s.size()){
        if(s[i] == 'R') x++;
        else if(s[i] == 'L') x--;
        else if(s[i] == 'U') y++;
        else if(s[i] == 'D') y--;
        h--;
        if(h < 0){
            cout << "No" << el;
            return 0;
        }
        if(mp[{x,y}] > 0){
            if(h < k){
                h = k;
                mp[{x,y}] = 0;
            }
        }
    }
    cout << "Yes" << el;
    return 0;
}
