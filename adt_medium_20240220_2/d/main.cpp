// 
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

bool check(vector<vector<int>>& a, vector<vector<int>>& b){
    bool ok = true;
    rep(i,a.size()){
        rep(j,a[i].size()){
            if(a[i][j] == 1){
                if(b[i][j] == 0) ok = false;
            }
        }
    }
    return ok;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(n)), b(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    rep(i,n)rep(j,n) cin >> b[i][j];
    bool ok = check(a, b);
    if(ok){
        cout << "Yes" << el;
        return 0;
    }
    vector<vector<int>> c = a;
    rep(i,n)rep(j,n){
        c[i][j] = a[n-1-j][i];
    }
    ok = check(c, b);
    if(ok){
        cout << "Yes" << el;
        return 0;
    }
    vector<vector<int>> d = c;
    rep(i,n)rep(j,n){
        d[i][j] = c[n-1-j][i];
    }
    ok = check(d, b);
    if(ok){
        cout << "Yes" << el;
        return 0;
    }
    vector<vector<int>> e = d;
    rep(i,n)rep(j,n){
        e[i][j] = d[n-1-j][i];
    }
    ok = check(e, b);
    if(ok){
        cout << "Yes" << el;
        return 0;
    }
    cout << "No" << el;
    return 0;
}