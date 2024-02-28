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

// 嘘解法だったため解説を見て実装する
int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h), t(h);
    rep(i,h) cin >> s[i];
    rep(i,h) cin >> t[i];
    // sとtそれぞれ行と列を転置する必要があった。
    vector<string> ns(w), nt(w);
    rep(i,h){
        rep(j,w){
            ns[j].push_back(s[i][j]);
            nt[j].push_back(t[i][j]);
        }
    }
    sort(all(ns));
    sort(all(nt));
    if(ns == nt) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}