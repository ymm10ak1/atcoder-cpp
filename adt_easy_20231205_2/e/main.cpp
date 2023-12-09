// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int h, w;

int check(const vector<string>& c, int n, int a, int b){
    int cnt = 0;
    repi(d, 1, n+1){
        if(a+d>=h || a-d<0 || b+d>=w || b-d<0) break;
        bool ok = false;
        if(c[a+d][b+d]=='#' && c[a+d][b-d]=='#' && c[a-d][b+d]=='#' && c[a-d][b-d]=='#') ok = true;
        else break;
        if(ok) cnt = d;
    }
    return cnt;
}

int main(){
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    int n = min(h, w);
    vector<int> cnt(n+1, 0);
    rep(i, h){
        rep(j, w){
            if(c[i][j] == '#'){
                int ni = check(c, n, i, j);
                if(ni > 0) ++cnt[ni];
            }
        }
    }
    repi(i, 1, n+1){
        if(i==n) cout << cnt[i] << el;
        else cout << cnt[i] << " ";
    }
    return 0;
}