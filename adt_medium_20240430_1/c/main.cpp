// C - Coloring Matrix
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(n)), b(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    rep(i,n)rep(j,n) cin >> b[i][j];
    vector<vector<int>> c(n,vector<int>(n));
    rep(x,4){
        bool ok = true;
        if(x>0){
            rep(i,n){
                rep(j,n){
                    c[n-1-j][i] = a[i][j];
                }
            }
            a = c;
        }
        rep(i,n){
            rep(j,n){
                if(a[i][j]==1 && b[i][j]==0) ok = false;
            }
        }
        if(ok){
            cout << "Yes" << el;
            return 0;
        }
    }
    cout << "No" << el;
    return 0;
}