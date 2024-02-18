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
    string s, t;
    cin >> s >> t;
    bool ok = false;
    if(s == t) ok = true;
    rep(i, s.size()-1){
        string ss = s;
        char tmp = ss[i];
        ss[i] = ss[i+1];
        ss[i+1] = tmp;
        if(ss == t) ok = true;
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}