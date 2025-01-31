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
    int n, m, h, k;
    string s;
    cin >> n >> m >> h >> k >> s;
    set<pair<int,int>> item;
    rep(i,m){
        int xi, yi;
        cin >> xi >> yi;
        item.emplace(xi,yi);
    }
    int x = 0, y = 0;
    rep(i,n){
        if(s[i] == 'R') x++;
        else if(s[i] == 'L') x--;
        else if(s[i] == 'U') y++;
        else y--;
        h--;
        if(h < 0){
            cout << "No" << el;
            return 0;
        }
        if(item.count({x,y}) && h<k){
            h = k;
            item.erase({x,y});
        }
    }
    cout << "Yes" << el;
    return 0;
}
