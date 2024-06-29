// 046 - I Love 46（★3）
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
    int n; cin >> n;
    map<int, int> mpa, mpb, mpc;
    rep(i,n){
        int ai; cin >> ai;
        mpa[ai%46]++;
    }
    rep(i,n){
        int bi; cin >> bi;
        mpb[bi%46]++;
    }
    rep(i,n){
        int ci; cin >> ci;
        mpc[ci%46]++;
    }
    ll ans = 0;
    rep(i,46){
        rep(j,46){
            rep(k,46){
                if((i+j+k)%46 == 0) ans += (ll)mpa[i]*mpb[j]*mpc[k];
            }
        }
    }
    cout << ans << el;
    return 0;
}
