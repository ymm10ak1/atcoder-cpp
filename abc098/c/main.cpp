// C - Attention
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
    int n;
    string s;
    cin >> n >> s;
    vector<int> e(n, 0), w(n, 0);
    rep(i, n){
        if(s[i] == 'E') e[i] = 1;
        else w[i] = 1;
    }
    vector<int> e_cs(n+1, 0), w_cs(n+1, 0);
    rep(i, n){
        e_cs[i+1] = e_cs[i]+e[i];
        w_cs[i+1] = w_cs[i]+w[i];
    }
    int ans = INF;
    repi(i, 1, n+1){
        int sum = (w_cs[i-1]-w_cs[0])+(e_cs[n]-e_cs[i]);
        ans = min(ans, sum);
    }
    cout << ans << el;
    return 0;
}