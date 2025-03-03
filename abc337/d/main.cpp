#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    map<int,vector<int>> oh, ow, xh, xw;
    rep(i,h)rep(j,w){
        if(s[i][j] == 'o') oh[i].push_back(j);
        if(s[i][j] == 'x') xh[i].push_back(j);
    }
    rep(i,w)rep(j,h){
        if(s[j][i] == 'o') ow[i].push_back(j);
        if(s[j][i] == 'x') xw[i].push_back(j);
    }
    int ans = INF;
    rep(i,h){
        rep(j,w-k+1){
            int cntx = upper_bound(all(xh[i]),j+k-1)-lower_bound(all(xh[i]),j);
            if(cntx >= 1) continue;
            int cnto = upper_bound(all(oh[i]),j+k-1)-lower_bound(all(oh[i]),j);
            ans = min(ans,k-cnto);
        }
    }
    rep(i,w){
        rep(j,h-k+1){
            int cntx = upper_bound(all(xw[i]),j+k-1)-lower_bound(all(xw[i]),j);
            if(cntx >= 1) continue;
            int cnto = upper_bound(all(ow[i]),j+k-1)-lower_bound(all(ow[i]),j);
            ans = min(ans,k-cnto);
        }
    }
    cout << (ans==INF?-1:ans) << el;
    return 0;
}
