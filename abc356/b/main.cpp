// B - Nutrients
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
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<vector<int>> x(n,vector<int>(m));
    rep(i,n) rep(j,m) cin >> x[i][j];
    vector<int> sum(m);
    rep(i,n) rep(j,m) sum[j] += x[i][j];
    bool ok = true;
    rep(i,m){
        if(sum[i] < a[i]) ok = false;
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
