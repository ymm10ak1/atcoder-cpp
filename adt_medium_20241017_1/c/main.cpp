// C
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
    vector<int> a(2*n);
    rep(i,2*n) cin >> a[i];
    int ans = 0;
    rep(i,2*n-1){
        int ai = a[i];
        repi(j,i+1,2*n){
            if(a[j]==ai && j-i==2) ans++; 
        }
    }
    cout << ans << el;
    return 0;
}
