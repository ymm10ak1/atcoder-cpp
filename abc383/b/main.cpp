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

int main(){
    int h, w, d;
    cin >> h >> w >> d;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<pair<int,int>> vp;
    rep(i,h) rep(j,w){
        if(s[i][j] == '.') vp.emplace_back(i,j);
    }
    int ans = 0;
    rep(i,vp.size()-1){
        rep(j,vp.size()){
            int si1 = vp[i].first, sj1 = vp[i].second;
            int si2 = vp[j].first, sj2 = vp[j].second;
            int cnt = 0;
            vector<vector<bool>> check(h,vector<bool>(w));
            rep(k,h){
                rep(l,w){
                    if(s[k][l] == '#') continue;
                    if(abs(k-si1)+abs(l-sj1)<=d && !check[k][l]){
                        cnt++;
                        check[k][l] = true;
                    }
                }
            }
            rep(k,h){
                rep(l,w){
                    if(s[k][l] == '#') continue;
                    if(abs(k-si2)+abs(l-sj2)<=d && !check[k][l]){
                        cnt++;
                        check[k][l] = true;
                    }
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << el;
    return 0;
}
