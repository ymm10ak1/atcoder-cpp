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

int main(){
    int n, m; cin >> n >> m;
    vector<int> p(n), c(n);
    vector<vector<int>> f(n);
    vector<vector<bool>> a(n,vector<bool>(m+1));
    rep(i,n){
        cin >> p[i] >> c[i];
        vector<int> ci(c[i]);
        rep(j,c[i]){
            cin >> ci[j];
            a[i][ci[j]] = true;
        }
        f[i] = ci;
    }
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            bool ok = false;
            if(p[i]>=p[j]){
                int cnt = 0;
                rep(k, c[i]){
                    if(a[j][f[i][k]]){ ++cnt; }
                }
                if(cnt == c[i]) ok = true;
                if(p[i]==p[j]){
                    cnt = 0;
                    rep(k, c[j]){
                        if(!a[i][f[j][k]]) ++cnt;
                    }
                    if(cnt == 0) ok = false;
                }
            }
            if(ok){
                cout << "Yes" << el;
                return 0;
            }
        }
    }
    cout << "No" << el;
    return 0;
}