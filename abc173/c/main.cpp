// C - H and V 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

bool check(const vector<vector<int>> &s, int k){
    int cnt = 0;
    rep(i, s.size()){
        rep(j, s[i].size()){
            if(s[i][j] == 1) cnt++; 
        }
    }
    if(cnt == k) return true;
    return false;
}

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    vector<vector<int>> s_init(h, vector<int>(w));
    // 白を"0", 黒を"1"とする
    rep(i, h) rep(j, w){
        if(c[i][j] == '.') s_init[i][j] = 0;
        else s_init[i][j] = 1;
    }
    int ans = 0;
    rep(bit_i,(1<<h)){
        rep(bit_j,(1<<w)){
            auto s = s_init;
            // 選択した行と列を赤色("2")に変更する
            rep(i, h){
                if(bit_i&(1<<i)){
                    rep(k, w) s[i][k] = 2;
                }
            }
            rep(j, w){
                if(bit_j&(1<<j)){
                    rep(k, h) s[k][j] = 2;
                }
            }
            if(check(s, k)) ans++;
        }
    }
    cout << ans << el;
    return 0;
}