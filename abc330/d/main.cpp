// D - Counting Ls
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
using P = pair<int,int>;

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> row(n), col(n);
    rep(i,n)rep(j,n) if(s[i][j] == 'o') row[i]++;
    rep(j,n)rep(i,n) if(s[i][j] == 'o') col[j]++;
    ll ans = 0;
    rep(i,n){
        rep(j,n){
            if(s[i][j] == 'o'){
                ans += (row[i]-1)*(col[j]-1);
            }
        }
    }
    cout << ans << el;
    return 0;
}
