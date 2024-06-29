// C - Minimization
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int idx = 0;
    rep(i,n) if(a[i] == 1) idx = i;
    int l = idx, r = n-1-idx;
    int ans = 0;
    if(n == k){
        ans = 1;
    }else{
        --k;
        ans += (l/k)+(r/k);
        int lr = (l%k), rr = (r%k);
        if(k > 1){
            if(lr+rr+1 <= k+1) ans++;
            else ans += 2;
        }
    }
    cout << ans << el;
    return 0;
}
