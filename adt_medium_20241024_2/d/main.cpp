// D
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
    int n, a;
    cin >> n >> a;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    int now = t[0]+a;
    vector<int> ans(n);
    ans[0] = now;
    repi(i,1,n){
        if(now <= t[i]){
            now = t[i]+a;
            ans[i] = now;
        }else{
            now += a;
            ans[i] = now;
        }
    }
    rep(i,n) cout << ans[i] << el;
    return 0;
}
