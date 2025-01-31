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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<bool> check(1005);
    int mi = INF, ma = 0;
    rep(i,n){
        check[a[i]] = true;
        mi = min(mi,a[i]);
        ma = max(ma,a[i]);
    }
    repi(i,mi,ma+1) if(!check[i]){
        cout << i << el;
        return 0;
    }
    return 0;
}
