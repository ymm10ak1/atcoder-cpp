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
    int d = 1;
    vector<vector<int>> ans(n,vector<int>(n));
    rep(i,n/2){
        repi(j,i,n-i) ans[i][j] = d++;
        repi(j,i+1,n-i) ans[j][n-i-1] = d++;
        rrep(j,n-i-1,i) ans[n-i-1][j] = d++;
        rrep(j,n-i-1,i+1) ans[j][i] = d++;
    }
    rep(i,n)rep(j,n){
        if(2*i==n-1 && 2*j==n-1) cout << "T";
        else cout << ans[i][j];
        if(j < n-1) cout << " ";
        else cout << el;
    }
    return 0;
}
