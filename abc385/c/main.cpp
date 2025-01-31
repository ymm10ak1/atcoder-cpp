// 
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
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ans = 1;
    rep(i,n){
        repi(j,1,n){
            int cnt = 1, now = 0;
            for(int k=i; k<n-j; k+=j){
                if(h[k] == h[k+j]){
                    cnt++;
                }else{
                    now = max(now, cnt);
                    cnt = 0;
                }
            }
            now = max(now, cnt);
            ans = max(ans, now);
        }
    }
    cout << ans << el;
    return 0;
}
