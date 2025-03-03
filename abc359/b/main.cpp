#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<int> a(2*n);
    rep(i,2*n) cin >> a[i];
    int ans = 0;
    rep(i,n){
        int idx = -1;
        bool ok = false;
        rep(j,2*n){
            if(a[j] == i+1){
                if(idx >= 0){
                    if(j-idx == 2) ok = true;
                }else{
                    idx = j;
                }
            }
        }
        if(ok) ans++;
    }
    cout << ans << el;
    return 0;
}
