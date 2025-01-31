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

int main(){
    string s; cin >> s;
    int n = s.size();
    int ans = 0;
    rep(i,n){
        string t = "";
        rep(j,n-i){
            t += s[i+j];
            bool ok = true;
            int m = t.size();
            rep(k,m) if(t[k] != t[m-1-k]) ok = false;
            if(ok) ans = max(ans, j+1);
        }
    }
    cout << ans << el;
    return 0;
}
