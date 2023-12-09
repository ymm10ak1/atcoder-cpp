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

bool check(const vector<vector<int>>& a, const vector<vector<int>>& b){
    int n = a.size();
    rep(i, n){
        rep(j, n){
            if(a[i][j] == 1){
                if(b[i][j] == 0) return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    rep(i, n) rep(j, n) cin >> b[i][j];
    if(check(a, b)){
        cout << "Yes" << el;
        return 0;
    }
    vector<vector<int>> c(n, vector<int>(n));
    // 時計回り
    rep(i, n){
        rep(j, n){
            c[j][n-1-i] = a[i][j];
        }
    }
    if(check(c, b)){
        cout << "Yes" << el;
        return 0;
    }
    vector<vector<int>> d(n, vector<int>(n));
    rep(i, n){
        rep(j, n){
            d[j][n-1-i] = c[i][j];
        }
    }
    if(check(d, b)){
        cout << "Yes" << el;
        return 0;
    }
    vector<vector<int>> e(n, vector<int>(n));
    rep(i, n){
        rep(j, n){
            e[j][n-1-i] = d[i][j];
        }
    }
    if(check(e, b)){
        cout << "Yes" << el;
        return 0;
    }
    cout << "No" << el;
    return 0;
}