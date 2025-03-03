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
    string s, t;
    cin >> s >> t;
    if(s[0] > s[1]) swap(s[0], s[1]);
    if(t[0] > t[1]) swap(t[0], t[1]);
    bool ok = false;
    if(s == t) ok = true;
    vector<string> a = {"AC", "AD", "BE", "BD", "CE"};
    vector<string> b = {"AB", "AE", "BC", "CD", "DE"};
    rep(i,a.size()){
        rep(j,a.size()){
            if(i == j) continue;
            if(a[i]==s && a[j]==t) ok = true;
            if(b[i]==s && b[j]==t) ok = true;
        }
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
