// B - Palindrome-phobia
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
    string s; cin >> s;
    int cnta = 0, cntb = 0, cntc = 0;
    rep(i,s.size()){
        if(s[i] == 'a') ++cnta;
        else if(s[i] == 'b') ++cntb;
        else if(s[i] == 'c') ++cntc;
    }
    int mincnt = min({cnta, cntb, cntc});
    cnta -= mincnt;
    cntb -= mincnt;
    cntc -= mincnt;
    bool ok = false;
    if(cnta<=1 && cntb<=1 && cntc<=1) ok = true;
    if(ok) cout << "YES" << el;
    else cout << "NO" << el;
    return 0;
}
