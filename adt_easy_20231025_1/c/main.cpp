// C - Distance Between Tokens
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    bool first = false;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == 'o'){
                if(first){
                    x2 = i;
                    y2 = j;
                }else{
                    x1 = i;
                    y1 = j;
                    first = true;
                }
            }
        }
    }
    int ans = abs(x1-x2)+abs(y1-y2);
    cout << ans << el;
    return 0;
}