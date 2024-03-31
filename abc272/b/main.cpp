// B - Everyone is Friends
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> x(m);
    rep(i,m){
        int k; cin >> k;
        vector<int> xi(k);
        rep(j,k) cin >> xi[j];
        x[i] = xi;
    }
    vector<vector<bool>> check(n,vector<bool>(n));
    rep(i,m){
        rep(j,x[i].size()){
            rep(k,x[i].size()){
                if(j == k) continue;
                check[x[i][j]-1][x[i][k]-1] = true;
            }
        }
    }
    bool ok = true;
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            if(!check[i][j] && !check[j][i]) ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << el;
    return 0;
}