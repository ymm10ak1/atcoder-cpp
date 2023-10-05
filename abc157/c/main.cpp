// C - Guess The Number
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define REPI(i, s, n) repi(i, s, n+1)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0, n)
#define REPL(i, s, n) repli(i, s, n+1)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int f(int n, int m, const vector<int> &s, const vector<int> &c){
    int v = INF;
    rep(i, 1000){
        string t = to_string(i);
        if(t.size() != n) continue;
        bool ok = true;
        rep(i, m){
            int ti = t[s[i]-1]-'0';
            if(ti != c[i]){
                ok = false;
                break;
            }
        }
        if(ok) v = min(v, i);
    }
    return v;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> s(m), c(m);
    rep(i, m) cin >> s[i] >> c[i];
    int ans = f(n, m, s, c);
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0; 
}