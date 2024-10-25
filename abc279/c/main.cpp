// C
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
    vector<string> s(h), t(h);
    rep(i,h) cin >> s[i];
    rep(i,h) cin >> t[i];
    vector<string> ns, nt;
    rep(i,w){
        string ss = "";
        string tt = "";
        rep(j,h){
            ss += s[j][i];
            tt += t[j][i];
        }
        ns.push_back(ss);
        nt.push_back(tt);
    }
    sort(all(ns));
    sort(all(nt));
    if(ns == nt) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
