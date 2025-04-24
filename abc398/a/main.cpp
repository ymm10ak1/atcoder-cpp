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
const int INF = (1<<30);
const ll LLINF = (1LL<<60);
// }}}

int main(){
    int n; cin >> n;
    string ans = "";
    if(n%2){
        rep(i,n){
            if(i == n/2) ans += '=';
            else ans += '-';
        }
    }else{
        rep(i,n){
            if(i==n/2-1 || i==n/2) ans += '=';
            else ans += '-';
        }
    }
    cout << ans << el;
    return 0;
}
