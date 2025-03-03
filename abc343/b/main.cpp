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
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    vector<vector<int>> ans(n);
    rep(i,n)rep(j,n){
        if(a[i][j] == 1) ans[i].push_back(j+1);
    }
    rep(i,n)rep(j,ans[i].size()) printf("%d%c", ans[i][j], j==(int)ans[i].size()-1?'\n':' '); 
    return 0;
}
