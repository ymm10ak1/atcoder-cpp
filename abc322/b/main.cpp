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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    string t1 = "", t2 = "";
    rep(i,n) t1 += t[i];
    rrep(i,m,m-n) t2 += t[i];
    reverse(all(t2));
    if(t1 == s && t2 == s) cout << 0 << el;
    else if(t1 == s) cout << 1 << el;
    else if(t2 == s) cout << 2 << el;
    else cout << 3 << el;
    return 0;
}
