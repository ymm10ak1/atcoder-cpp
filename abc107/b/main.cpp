// B - Grid Compression
#include<bits/stdc++.h>
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
using namespace std;
using ll = long long;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    vector<vector<bool>> check(h, vector<bool>(w, false));
    vector<bool> h_check(w, false), w_check(h, false);
    rep(i, h){
        int s_cnt = 0;
        rep(j, w){
            if(a[i][j] == '.') ++s_cnt;
        }
        if(s_cnt == w) w_check[i] = true;
    }
    rep(i, w){
        int s_cnt = 0;
        rep(j, h){
            if(a[j][i] == '.') ++s_cnt;
        }
        if(s_cnt == h) h_check[i] = true;
    }
    rep(i, h){
        rep(j, w){
            if(h_check[j] || w_check[i]) check[i][j] = true;
        }
    }
    rep(i, h){
        rep(j, w){
            if(!check[i][j]) cout << a[i][j];
        }
        if(!w_check[i]) cout << endl;
    }
    return 0;
}