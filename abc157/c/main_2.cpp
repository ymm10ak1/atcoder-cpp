// C - Guess The Number
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
    vector<int> s(m), c(m);
    rep(i,m) cin >> s[i] >> c[i];
    int d[3] = { -1, -1, -1 };
    bool ok = true;
    rep(i,m){
        if(s[i] == 1){
            if(d[0] == -1) d[0] = c[i];
            else if(d[0] != c[i]) ok = false;
        }else if(s[i] == 2){
            if(d[1] == -1) d[1] = c[i];
            else if(d[1] != c[i]) ok = false;
        }else if(s[i] == 3){
            if(d[2] == -1) d[2] = c[i];
            else if(d[2] != c[i]) ok = false;
        }
    }
    if(n>=2 && d[0]==0) ok = false;
    if(!ok){
        cout << -1 << el;
        return 0;
    }
    int ans = 0;
    if(n == 1){
        if(d[0] != -1) ans = d[0];
    }else if(n == 2){
        ans = (d[0]==-1 ? 10 : d[0]*10);
        ans += (d[1]==-1 ? 0 : d[1]);
    }else if(n == 3){
        ans = (d[0]==-1 ? 100 : d[0]*100);
        ans += (d[1]==-1 ? 0 : d[1]*10);
        ans += (d[2]==-1 ? 0 : d[2]);
    }
    cout << ans << el;
    return 0;
}
