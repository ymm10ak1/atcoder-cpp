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

// dx, dyのサイズ
const int D_SIZE = 8;
// 8方向(上、下、右、左、右下、左下、右上、左上)を用意する
const int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool snuke_check(const string& s){
    return s=="snuke" ? true : false;
}

vector<pair<int, int>> make_res(int sh, int sw, int d_idx){
    vector<pair<int, int>> res;
    res.push_back({++sh, ++sw});
    rep(i, 4){
        sh += dx[d_idx]; sw += dy[d_idx];
        res.push_back({sh, sw});
    }
    return res;
}

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<pair<int, int>> res;
    rep(i, h){
        rep(j, w){
            rep(k, D_SIZE){
                string t = s[i].substr(j, 1);
                int si = i, sj = j;
                bool ng = false;
                rep(l, 4){
                    si += dx[k]; sj += dy[k];
                    if(si<0 || si>=h || sj<0 || sj>=w){
                        ng = true;
                        break;
                    }
                    t += s[si][sj];
                }
                if(ng) continue;
                if(snuke_check(t)){
                    res = make_res(i, j, k);
                    for(auto p : res){
                        cout << p.first << " " << p.second << el;
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}