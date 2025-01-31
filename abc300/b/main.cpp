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
    int h, w;
    cin >> h >> w;
    vector<string> a(h), b(h);
    rep(i,h) cin >> a[i];
    rep(i,h) cin >> b[i];
    bool ok = false;
    if(a == b) ok = true;
    rep(wi,w){
        vector<string> ah(h);
        rep(i,h){
            string s = "";
            rep(j,w) s += a[i][(j+wi)%w];
            ah[i] = s;
        }
        rep(hi,h){
            vector<string> aw(h);
            rep(k,h){
                string t = ah[(k+hi)%h];
                aw[k] = t;
            }
            if(aw == b) ok = true;
        }
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
