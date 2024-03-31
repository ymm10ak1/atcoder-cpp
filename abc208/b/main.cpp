// B - Factirial Yen Coin
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

int fac[12];

int main(){
    int p; cin >> p;
    fac[1] = 1;
    repi(i,2,11) fac[i] = i*fac[i-1];
    int ans = 0;
    rrepi(i,11,1){
        if(p < fac[i]) continue;
        int d = ((p/fac[i])>=100) ? 100 : (p/fac[i]);
        ans += d;
        p -= fac[i]*d;
        if(p <= 0) break;
    }
    cout << ans << el;
    return 0;
}