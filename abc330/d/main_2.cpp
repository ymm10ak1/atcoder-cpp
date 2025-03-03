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
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    map<int,vector<int>> mph, mpw;
    rep(i,n)rep(j,n) if(s[i][j] == 'o'){
        mph[i].push_back(j);
        mpw[j].push_back(i);
    }
    rep(i,n){
        sort(all(mph[i]));
        sort(all(mpw[i]));
    }
    ll ans = 0;
    rep(i,n)rep(j,n){
        if(s[i][j] == 'o'){
            // NOTE: ここでs[i][j]が丸のときのjを左右に分けて数えているが
            // cntr+cntl = (mpw[j].size()-1)*{(mph[i].size()-r-1)+r} = (mpw[j].size()-1)*(mph[i].size()-1)
            // と変形できる。つまり、s[i][j]が丸のときの(i行目の丸の個数-1)*(j列目の丸の個数-1)の総和で答えが求まる
            int r = lower_bound(all(mph[i]),j)-mph[i].begin();
            int cntr = (mpw[j].size()-1)*(mph[i].size()-r-1);
            int cntl = (mpw[j].size()-1)*r;
            ans += (ll)cntr+cntl;
        }
    }
    cout << ans << el;
    return 0;
}
