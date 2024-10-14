// C - Cross
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
vector<int> ans;
vector<vector<bool>> used;

void f(const vector<string>& c, int a, int b){
    int d = 1;
    while(1){
        if(a-d<0 || b-d<0 || a+d>=h || b+d>=w) break;
        if(c[a-d][b-d]!='#' || c[a-d][b+d]!='#' || c[a+d][b-d]!='#' || c[a+d][b+d]!='#') break;
        if(d == 1) used[a][b] = true;
        used[a-d][b-d] = used[a-d][b+d] = used[a+d][b-d] = used[a+d][b+d] = true;
        d++;
    }
    ans[d-1]++;
    return;
}

int main(){
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    ans.resize(min(h,w)+1,0);
    used.resize(h,vector<bool>(w,false));
    rep(i,h)rep(j,w){
        if(c[i][j]=='#' && !used[i][j]) f(c, i, j);
    }
    repi(i,1,ans.size()) printf("%d%c", ans[i], i==(int)ans.size()-1?'\n':' ');
    return 0;
}