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

ll cnt = 0;

ll gcd(ll x, ll y){
    if(x%y == 0){
        if(x > y) cnt += (x-y)/y;
        return y;
    }else{
        if(x > y) cnt += x/y;
        return gcd(y, x%y);
    }
}

int main(){
    ll a, b;
    cin >> a >> b;
    if(a%b == 0){
        cnt = (a-b)/b;
    }else if(b%a == 0){
        cnt = (b-a)/a;
    }else{
        gcd(a, b);
    }
    cout << cnt << el;
    return 0;
}
