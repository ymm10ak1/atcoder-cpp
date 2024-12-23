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

int h, w, k;
int ans;

void f(const vector<string>& s, set<pair<int,int>> st, int cnt, int x, int y){
    if(x<0 || y<0 || x>=h || y>=w) return;
    if(s[x][y] == '#') return;
    if(st.count({x,y}) == 1) return;
    st.insert({x,y});
    if(cnt == k){
        ans++;
        return;
    }
    if(x+1<h && s[x+1][y]=='.' && st.count({x+1,y})==0){
        f(s,st,cnt+1,x+1,y);
    }
    if(y+1<w && s[x][y+1]=='.' && st.count({x,y+1})==0){
        f(s,st,cnt+1,x,y+1);
    }
    if(x-1>=0 && s[x-1][y]=='.' && st.count({x-1,y})==0){
        f(s,st,cnt+1,x-1,y);
    }
    if(y-1>=0 && s[x][y-1]=='.' && st.count({x,y-1})==0){
        f(s,st,cnt+1,x,y-1);
    }
}

int main(){
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h)rep(j,w){
        if(s[i][j] == '#') continue;
        set<pair<int,int>> st;
        f(s,st,0,i,j);
    }
    cout << ans << el;
    return 0;
}
