// C - When I hit my pocket...
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
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans = 0;
    if(k<=a || a>=b){
        ans = 1+k;
    }else{
        if(b-a == 1){
            ans = 1+k;
        }else{
            ans = b;
            ll kk = k-a-1;
            if(kk>0 && kk<2) ++ans;
            else ans += (kk/2*(b-a))+(kk%2);
        }
    }
    cout << ans << el;
    return 0;
}
