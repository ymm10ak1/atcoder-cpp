// B - Grid Compression
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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    vector<bool> r(h), c(w);
    rep(i,h){
        rep(j,w){
            if(a[i][j] == '#'){
                r[i] = true;
                c[j] = true;
            }
        }
    }
    rep(i,h){
        if(!r[i]) continue;
        rep(j,w){
            if(!c[j]) continue;
            cout << a[i][j];
        }
        cout << el;
    }
    return 0;
}
