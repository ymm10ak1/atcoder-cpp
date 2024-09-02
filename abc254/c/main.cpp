// C - K Swap
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
    vector<vector<int>> b(k);
    rep(i,n) b[i%k].push_back(a[i]);
    rep(i,k) sort(all(b[i]));
    rep(i,k){
        rep(j,b[i].size()) a[i+j*k] = b[i][j];
    }
    bool ok = true;
    rep(i,n-1) if(a[i] > a[i+1]) ok =false;
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
