// C - 怪文書
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
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<vector<int>> cnt(n,vector<int>(26,0));
    rep(i,n) rep(j,s[i].size()) cnt[i][s[i][j]-97]++;
    string ans = "";
    rep(i,26){
        int minx = cnt[0][i];
        rep(j,n) minx = min(minx, cnt[j][i]);
        rep(j,minx) ans += 'a'+i;
    }
    cout << ans << el;
    return 0;
}
