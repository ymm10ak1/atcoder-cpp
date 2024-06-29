// C - Reconciled?
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

constexpr int M = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    if(abs(n-m) == 1){
        ans = 1;
        rrepi(i,n+1,1) ans = (ans*i)%M;
        rrepi(i,m+1,1) ans = (ans*i)%M;
    }else if(abs(n-m) == 0){
        ans = 1;
        rrepi(i,n+1,1) ans = (ans*i)%M;
        rrepi(i,n+1,1) ans = (ans*i)%M;
        ans = (ans*2)%M;
    }
    cout << ans << el;
    return 0;
}
