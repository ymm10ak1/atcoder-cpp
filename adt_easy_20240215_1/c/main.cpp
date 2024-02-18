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

void print_arr(vector<pair<int, int>>& p){
    rep(i, p.size()){
        cout << p[i].first+1 << " " << p[i].second+1 << el;
    }
}

bool check(string s, vector<pair<int, int>>& p ,bool reverse_check){
    if(reverse_check) reverse(all(s));
    if(s == "snuke"){
        if(reverse_check) reverse(all(p));
        print_arr(p);
        return true;
    }
    return false;
}

// NOTE: 解説を見るともっと良い解法があった(あるxy座標から8方向のいずれかに伸ばして調べるやり方)
int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    // 横方向
    rep(i,h){
        rep(j,w){
            vector<pair<int,int>> v;
            string yoko = "";
            bool ok = true;
            rep(k,5){
                if(j+k>=w){ ok = false; break; }
                yoko += s[i][j+k];
                v.push_back({i, j+k});
            }
            if(ok){
                if(check(yoko, v, false)) return 0;
                if(check(yoko, v, true)) return 0;
            }
        }
    }
    // 縦方向
    rep(i,w){
        rep(j,h){
            vector<pair<int,int>> v;
            string tate = "";
            bool ok = true;
            rep(k,5){
                if(j+k>=h){ ok = false; break; }
                tate += s[j+k][i];
                v.push_back({j+k, i});
            }
            if(ok){
                if(check(tate, v, false)) return 0;
                if(check(tate, v, true)) return 0;
            }
        }
    }
    // 斜め方向
    rep(i,h){
        rep(j,w){
            vector<pair<int,int>> v;
            string naname = "";
            bool ok = true;
            rep(k,5){
                if(i+k>=h || j+k>=w){ ok = false; break; }
                naname += s[i+k][j+k];
                v.push_back({i+k, j+k});
            }
            if(ok){
                if(check(naname, v, false)) return 0;
                if(check(naname, v, true)) return 0;
            }
        }
    }
    rep(i,h){
        rrepi(j,w,0){
            vector<pair<int,int>> v;
            string naname = "";
            bool ok = true;
            rep(k,5){
                if(i+k<0 || j-k<0){ ok = false; break; }
                naname += s[i+k][j-k];
                v.push_back({i+k, j-k});
            }
            if(ok){
                if(check(naname, v, false)) return 0;
                if(check(naname, v, true)) return 0;
            }
        }
    }
    return 0;
}