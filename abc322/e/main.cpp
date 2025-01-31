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

// BUG: 解けていない
int main(){
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> c(n);
    vector<vector<int>> a(n,vector<int>(k));
    rep(i,n){
        cin >> c[i];
        rep(j,k) cin >> a[i][j];
    }
    return 0;
}
