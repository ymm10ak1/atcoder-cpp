// C - Bowls ans Dishes
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
    vector<int> a(m), b(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        --a[i]; --b[i];
    }
    int k; cin >> k;
    vector<int> c(k), d(k);
    rep(i,k){
        cin >> c[i] >> d[i];
        --c[i]; --d[i];
    }
    int ans = 0;
    rep(s,(1<<k)){
        vector<int> dish(n,0);
        rep(i,k){
            if((s>>i) & 1) ++dish[d[i]];
            else ++dish[c[i]];
        }
        int cnt = 0;
        rep(i,m) if(dish[a[i]]>=1 && dish[b[i]]>=1) ++cnt;
        ans = max(ans, cnt);
    }
    cout << ans << el;
    return 0;
}
