// C - Grid Repainting 2
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

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};


int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                bool ok = false;
                rep(k,4){
                    int nx = i+dx[k], ny = j+dy[k];
                    if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                    // 上下左右2マスになっているか
                    if(s[nx][ny] == '#') ok = true;
                }
                // 対象マスの上下左右が黒色でない場合はNo
                if(!ok){
                    cout << "No" << el;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << el;
    return 0;
}
