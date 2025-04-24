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
    int n, t, a;
    cin >> n >> t >> a;
    if(t == a){
        cout << "No" << el;
        return 0;
    }
    bool ok = true;
    n -= t+a;
    if(t > a){
        rep(i,n) a++;
        if(t < a) ok = false;
    }else{
        rep(i,n) t++;
        if(t > a) ok = false;
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
