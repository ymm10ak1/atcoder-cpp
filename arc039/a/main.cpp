// A - A - B problem
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

int f(string a, string b, int idx, bool isA){
    int ret = -INF;
    rep(i,10){
        if(idx==0 && i==0) continue;
        if(isA) a[idx] = '0'+i;
        else b[idx] = '0'+i;
        int d = stoi(a)-stoi(b);
        ret = max(ret, d);
    }
    return ret;
}

int main(){
    string a, b;
    cin >> a >> b;
    int ans = f(a, b, 0, true);
    ans = max(ans, f(a, b, 1, true));
    ans = max(ans, f(a, b, 2, true));
    ans = max(ans, f(a, b, 0, false));
    ans = max(ans, f(a, b, 1, false));
    ans = max(ans, f(a, b, 2, false));
    cout << ans << el;
    return 0;
}
