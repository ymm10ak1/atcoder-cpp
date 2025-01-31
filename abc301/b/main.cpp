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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n-1){
        if(abs(a[i]-a[i+1]) == 1){
            cout << a[i] << " ";
        }else{
            if(a[i] < a[i+1]){
                repi(j,a[i],a[i+1]) cout << j << " ";
            }else{
                rrepi(j,a[i]+1,a[i+1]+1) cout << j << " ";
            }
        }
    }
    cout << a[n-1] << el;
    return 0;
}
