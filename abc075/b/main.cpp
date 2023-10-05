// B - Minesweeper
#include<bits/stdc++.h>
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
using namespace std;
using ll = long long;

const vector<int> x = {-1, -1, -1, 0, 0, 1, 1, 1};
const vector<int> y = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<string> s;
vector<vector<int>> ans;

void f(int h, int w){
    rep(i, h){
        rep(j, w){
            // 今いるマスが爆弾マスならスキップ
            if(s[i][j] == '#'){
                ans[i][j] = -1;
                continue;
            }
            rep(k, x.size()){
                if(i+x[k] < 0 || i+x[k] >= h || j+y[k] < 0 || j+y[k] >= w) continue;
                // 爆弾に該当するマスがあれば+1する
                if(s[i+x[k]][j+y[k]] == '#') ++ans[i][j];
            }
        }
    }
}

int main(){
    int h, w;
    cin >> h >> w;
    s.resize(h);
    ans.resize(h, vector<int>(w, 0));
    rep(i, h) cin >> s[i];
    f(h, w);
    rep(i, h){
        rep(j, w){
            if(ans[i][j] == -1){
                if(j == w-1) cout << "#" << endl;
                else cout << "#";
            }else{
                if(j == w-1) cout << ans[i][j] << endl;
                else cout << ans[i][j];
            } 
        }
    }
    return 0;
}