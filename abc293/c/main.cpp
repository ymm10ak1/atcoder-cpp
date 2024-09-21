// C - Make Takahashi Happy
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

int h, w, ans = 0;
vector<int> v;

bool check(){
    map<int,bool> mp;
    bool ok = true;
    rep(i,v.size()){
        if(mp[v[i]]) ok = false;
        else mp[v[i]] = true;
    }
    return ok;
}

void f(const vector<vector<int>>& a, int x, int y){
    v.push_back(a[x][y]);
    if(x==h-1 && y==w-1){
        if(check()) ans++;
        return;
    }
    // 下に移動する場合
    if(x < h-1){
        f(a, x+1, y);
        v.pop_back();
    }
    // 右に移動する場合
    if(y < w-1){
        f(a, x, y+1);
        v.pop_back();
    }
}

int main(){
    cin >> h >> w;
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    f(a, 0, 0);
    cout << ans << el;
    return 0;
}
