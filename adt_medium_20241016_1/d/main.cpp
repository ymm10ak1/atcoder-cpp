// D
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
    vector<vector<int>> a(m,vector<int>(n));
    set<pair<int,int>> st;
    rep(i,m)rep(j,n) cin >> a[i][j];
    rep(i,m){
        rep(j,n-1){
            int a1 = a[i][j], a2 = a[i][j+1];
            if(a1 > a2) swap(a1,a2);
            st.insert({a1,a2});
        }
    }
    int ans = 0;
    repi(i,1,n){
        repi(j,i+1,n+1){
            if(st.count({i,j}) == 0) ans++;
        }
    }
    cout << ans << el;
    return 0;
}
