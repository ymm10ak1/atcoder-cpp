#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans = INF;
    rep(bi,(1<<n)){
        vector<bool> check(m);
        int cnt = 0;
        rep(i,n){
            if(bi>>i & 1){
                cnt++;
                rep(j,m) if(s[i][j] == 'o') check[j] = true;
            }
        }
        bool ok = true;
        rep(i,m) if(!check[i]) ok = false;
        if(ok) ans = min(ans, cnt);
    }
    cout << ans << el;
    return 0;
}
