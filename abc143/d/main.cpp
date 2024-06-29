// D - Triangles
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
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(all(l));
    int ans = 0;
    // 解説を見たところ3重ループでも間に合うみたい
    rep(i,n-1){
        repi(j,i+1,n){
            // |a-b| < c < a+b を満たすcの個数を求める
            int lidx = upper_bound(all(l), abs(l[i]-l[j]))-l.begin();
            int ridx = lower_bound(all(l), l[i]+l[j])-l.begin();
            if(ridx-lidx > 1){
                ans += ridx-lidx;
                if(lidx <= i) ans--;
                if(lidx <= j) ans--;
            }
        }
    }
    cout << ans/3 << el;
    return 0;
}
