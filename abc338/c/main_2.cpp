#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<int> q(n), a(n), b(n);
    rep(i,n) cin >> q[i];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    int maxa = INF;
    rep(i,n) if(a[i]>0) maxa = min(maxa, q[i]/a[i]);
    
    int ans = 0;
    for(int i=maxa; i>=0; --i){
        vector<int> nq = q;
        rep(j,n) nq[j] -= i*a[j];
        int maxb = INF;
        rep(j,n) if(b[j] > 0) maxb = min(maxb,nq[j]/b[j]);
        ans = max(ans,i+maxb);
    }
    cout << ans << el;
    return 0;
}
