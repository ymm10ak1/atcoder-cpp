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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<vector<int>> cnt(105, vector<int>(105));
    rep(i, n){
        repi(j, a[i], b[i]){
            repi(k, c[i], d[i]){
                cnt[j][k] = 1;
            }
        }
    }
    int ans = 0;
    rep(i, 105){
        rep(j, 105){
            if(cnt[i][j] == 1) ++ans;
        }
    }
    cout << ans << el;
    return 0;
}