// C
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
    string s, t;
    cin >> s >> t;
    string t1 = t.substr(0,n);
    string t2 = t.substr(m-n);
    int ans = 3;
    if(s==t1 && s==t2) ans = 0;
    else if(s==t1) ans = 1;
    else if(s==t2) ans = 2;
    cout << ans << el;
    return 0;
}
