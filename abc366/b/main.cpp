// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 2e9;
const ll LLINF = 2e18;
// }}}

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int m = 0;
    rep(i,n) m = max(m, (int)s[i].size());
    vector<vector<char>> t(n,vector<char>(m,' '));
    rep(i,n)rep(j,s[i].size()) t[i][j] = s[i][j];
    rep(i,m){
        bool alp = false;
        rep(j,n){
            if(t[j][i] != ' ') alp = true;
            if(t[j][i]==' ' && alp) t[j][i] = '*';
        }
    }
    vector<vector<char>> ans(m,vector<char>(n,' '));
    rep(i,n)rep(j,m) ans[j][n-1-i] = t[i][j];
    rep(i,m){
        rep(j,n){
            if(ans[i][j] == ' ') break;
            cout << ans[i][j];
        }
        cout << el;
    }
    return 0;
}
