// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    ll x;
    cin >> x;
    ll ans = 0;
    if(x < 0){
        if(x%10 == 0) ans = x/10;
        else ans = x/10-1;
    }else{
        ans = x/10;
    }
    cout << ans << el;
    return 0;
}