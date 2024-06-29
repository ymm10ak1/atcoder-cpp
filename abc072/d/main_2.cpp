// D - Derangement
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

// NOTE: 解説見るとp[i],p[i+1]でswapすればいいみたい(p[n-1]がnのときだけp[i-1]とp[i]をswapする)
int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n){
        cin >> p[i];
        --p[i];
    }
    int ans = 0, cnt = 0;
    rep(i,n){
        while(p[i] == i){
            ++i;
            ++cnt;
        }
        ans += cnt/2+cnt%2;
        cnt = 0;
    }
    cout << ans << el;
    return 0;
}
