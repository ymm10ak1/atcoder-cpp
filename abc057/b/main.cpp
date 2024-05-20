// B - Checkpoints
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
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<int> c(m), d(m);
    rep(i,m) cin >> c[i] >> d[i];
    vector<int> ans;
    rep(i,n){
        int minp = INF, minidx;
        rep(j,m){
            int dist = abs(a[i]-c[j])+abs(b[i]-d[j]);
            if(minp > dist){
                minp = dist;
                minidx = j+1;
            }
        }
        ans.push_back(minidx);
    }
    rep(i,ans.size()) cout << ans[i] << el;
    return 0;
}
