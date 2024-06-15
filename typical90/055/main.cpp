// 055 - Select 5（★2）
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
    int n, p, q;
    cin >> n >> p >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n-4){
        repi(j,i+1,n-3){
            repi(k,j+1,n-2){
                repi(l,k+1,n-1){
                    repi(m,l+1,n){
                        ll seki = ((((a[i]*a[j])%p*a[k])%p*a[l])%p*a[m])%p;
                        if(seki == (ll)q) ++ans;
                    }
                }
            }
        }
    }
    cout << ans << el;
    return 0;
}
