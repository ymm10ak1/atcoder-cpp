// F
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
    int h1, w1;
    cin >> h1 >> w1;
    vector<vector<int>> a(h1,vector<int>(w1));
    rep(i,h1)rep(j,w1) cin >> a[i][j];
    int h2, w2;
    cin >> h2 >> w2;
    vector<vector<int>> b(h2,vector<int>(w2));
    rep(i,h2)rep(j,w2) cin >> b[i][j];
    rep(biti,(1<<h1)){
        if(biti == 0) continue;
        rep(bitj,(1<<w1)){
            vector<bool> nh(h1), nw(w1);
            int cnth = 0, cntw = 0;
            rep(i,h1){
                if((biti>>i) & 1){
                    nh[i] = true;
                    cnth++;
                }
            }
            rep(j,w1){
                if((bitj>>j) & 1){
                    nw[j] = true;
                    cntw++;
                }
            }
            if(cnth != h2 || cntw != w2) continue;
            vector<vector<int>> c;
            rep(i,h1){
                vector<int> v;
                rep(j,w1){
                    if(nh[i] && nw[j]) v.push_back(a[i][j]);
                }
                if(v.size() > 0) c.push_back(v);
            }
            bool ok = true;
            rep(i,c.size()){
                rep(j,c[i].size()) if(c[i][j] != b[i][j]) ok = false;
            }
            if(ok){
                cout << "Yes" << el;
                return 0;
            }
        }
    }
    cout << "No" << el;
    return 0;
}
