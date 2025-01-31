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

int h, w, n;
vector<string> c;
vector<int> ans;

int f(int a, int b){
    int res = 0;
    repi(d,1,n+1){
        if(a-d<0 || a+d>=h || b-d<0 || b+d>=w) break;
        if(c[a+d][b+d] == '.') break;
        if(c[a+d][b-d] == '.') break;
        if(c[a-d][b+d] == '.') break;
        if(c[a-d][b-d] == '.') break;
        res++;
    }
    bool ok = false;
    if(a+res+1>=h || a-res-1<0 || b+res+1>=w || b-res-1<0) ok = true;
    if(a+res+1<h && b+res+1<w && c[a+res+1][b+res+1]=='.') ok = true;
    if(a+res+1<h && b-res-1>=0 && c[a+res+1][b-res-1]=='.') ok = true;
    if(a-res-1>=0 && b+res+1<w && c[a-res-1][b+res+1]=='.') ok = true;
    if(a-res-1>=0 && b-res-1>=0 && c[a-res-1][b-res-1]=='.') ok = true;
    if(ok) return res;
    return 0;
}

int main(){
    cin >> h >> w;
    c.resize(h);
    rep(i,h) cin >> c[i];
    n = min(h,w);
    ans.assign(n+1,0);
    rep(i,h)rep(j,w){
        if(c[i][j] == '#'){
            int res = f(i,j);
            ans[res]++;
        }
    }
    repi(i,1,n+1) printf("%d%c", ans[i], i==n?'\n':' ');
    return 0;
}
