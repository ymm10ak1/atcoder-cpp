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

bool solve(){
    const int n = 9;
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    rep(i,n){
        vector<int> cnth(10), cntw(10);
        rep(j,n) cnth[a[i][j]]++;
        rep(j,n) cntw[a[j][i]]++;
        repi(j,1,10){
            if(cnth[j]==0 || cntw[j]==0) return false;
        }
    }
    for(int i=0; i<n; i+=3){
        for(int j=0; j<n; j+=3){
            vector<int> cnt(10);
            rep(k,3)rep(l,3) cnt[a[i+k][j+l]]++;
            repi(k,1,10) if(cnt[k] == 0) return false;
        }
    }

    return true;
}

int main(){
    if(solve()) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
