// C - March
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
    ll a = 0, c = 0, h = 0, m = 0, r = 0;
    rep(i,n){
        if(s[i][0] == 'A') a++;
        if(s[i][0] == 'C') c++;
        if(s[i][0] == 'H') h++;
        if(s[i][0] == 'M') m++;
        if(s[i][0] == 'R') r++;
    }
    ll ans = a*(c*h+c*m+c*r+h*m+h*r+m*r)+c*(h*m+h*r+m*r)+h*m*r;
    cout << ans << el;
    return 0;
}
