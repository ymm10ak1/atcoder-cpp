// B - Chrismas Trees
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
    ll a, m, l, r;
    cin >> a >> m >> l >> r;
    ll ans = 0;
    if(l<=a && a<=r){
        ans = abs(a-l)/m+abs(r-a)/m+1;
    }else if(a < l){
        ans = abs(r-a)/m-abs(l-a)/m;
        if(l == r){
            if(abs(a-l)%m == 0) ++ans;
        }else{
            if(abs(r-l)%m == 0) ++ans;
        }
    }else if(r < a){
        ans = abs(a-l)/m-abs(a-r)/m;
        if(l == r){
            if(abs(a-l)%m == 0) ++ans;
        }else{
            if(abs(r-l)%m == 0) ++ans;
        }
    }
    cout << ans << el;
    return 0;
}
