// B44 - Grid Operations
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
    vector<vector<int>> a(n, vector<int>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    int q; cin >> q;
    vector<int> T(n);
    rep(i,n) T[i] = i;
    rep(i,q){
        int type, x, y;
        cin >> type >> x >> y;
        --x; --y;
        if(type == 1){
            int tmp = T[x];
            T[x] = T[y]; T[y] = tmp;
        }else if(type == 2){
            cout << a[T[x]][y] << el;
        }
    }
    return 0;
}