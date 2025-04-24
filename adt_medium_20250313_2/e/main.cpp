// template {{{
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 2e9;
const ll LLINF = 2e18;
// }}}

bool solve(){
    const int n = 9;
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    rep(i,n){
        vector<int> cnt(n);
        rep(j,n) if(cnt[a[i][j]-1]++ > 0) return false;
    }
    rep(i,n){
        vector<int> cnt(n);
        rep(j,n) if(cnt[a[j][i]-1]++ > 0) return false;
        
    }
    for(int i=0; i<n; i+=3){
        for(int j=0; j<n; j+=3){
            vector<int> cnt(n);
            repi(k,i,i+3)repi(l,j,j+3) if(cnt[a[k][l]-1]++ > 0) return false;
        }
    }
    return true;
}

int main(){
    if(solve()) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
