// C - Many Segments
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
    vector<int> t(n), l(n), r(n);
    rep(i,n) cin >> t[i] >> l[i] >> r[i];
    int ans = 0;
    // NOTE: 解説見るとl,rを2倍して開区間の箇所を+(または-)1することですべて閉区間にできて実装がスッキリする
    rep(i,n-1){
        repi(j,i+1,n){
            if(t[i] == 1){
                if(t[j] == 1){
                    if(r[i]<l[j] || r[j]<l[i]) continue;
                }else if(t[j] == 2){
                    if(r[i]<l[j] || r[j]<=l[i]) continue;
                }else if(t[j] == 3){
                    if(r[i]<=l[j] || r[j]<l[i]) continue;
                }else if(t[j] == 4){
                    if(r[i]<=l[j] || r[j]<=l[i]) continue;
                }
            }else if(t[i] == 2){
                if(t[j] == 1){
                    if(r[i]<=l[j] || r[j]<l[i]) continue;
                }else if(t[j] == 2){
                    if(r[i]<=l[j] || r[j]<=l[i]) continue;
                }else if(t[j] == 3){
                    if(r[i]<=l[j] || r[j]<l[i]) continue;
                }else if(t[j] == 4){
                    if(r[i]<=l[j] || r[j]<=l[i]) continue;
                }
            }else if(t[i] == 3){
                if(t[j] == 1){
                    if(r[i]<l[j] || r[j]<=l[i]) continue;
                }else if(t[j] == 2){
                    if(r[i]<l[j] || r[j]<=l[i]) continue;
                }else if(t[j] == 3){
                    if(r[i]<=l[j] || r[j]<=l[i]) continue;
                }else if(t[j] == 4){
                    if(r[i]<=l[j] || r[j]<=l[i]) continue;
                }
            }else if(t[i] == 4){
                if(t[j] == 1){
                    if(r[i]<=l[j] || r[j]<=l[i]) continue;
                }else if(t[j] == 2){
                    if(r[i]<=l[j] || r[j]<=l[i]) continue;
                }else if(t[j] == 3){
                    if(r[i]<=l[j] || r[j]<=l[i]) continue;
                }else if(t[j] == 4){
                    if(r[i]<=l[j] || r[j]<=l[i]) continue;
                }
            }
            ++ans;
        }
    }
    cout << ans << el;
    return 0;
}
