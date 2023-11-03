// C - たくさんの数式
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
    string s;
    cin >> s;
    ll ans = 0;
    rep(bit, (1<<s.size()-1)){
        ll v = 0;
        string t = s.substr(0, 1);
        rep(i, s.size()-1){
            if(bit&(1<<i)){
                v += stoll(t);
                t = s.substr(i+1, 1);
            }else{
                t += s.substr(i+1, 1);
            }
        }
        v += stoll(t);
        ans += v;
    }
    cout << ans << el;
    return 0;
}