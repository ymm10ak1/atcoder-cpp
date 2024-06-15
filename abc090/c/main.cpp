// C - Flip,Flip, and Flip......
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
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    if(n==1 && m==1) ans = 1;
    else if(n==1 && m>1) ans = m-2;
    else if(m==1 && n>1) ans = n-2;
    else ans = (ll)(n-2)*(m-2);
    cout << ans << el;
    return 0;
}
