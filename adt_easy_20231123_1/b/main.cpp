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
    vector<string> s(2);
    rep(i, 2) cin >> s[i];
    bool ok = true;
    if(s[0][0]=='.' && s[0][1]=='#' && s[1][0]=='#' && s[1][1]=='.') ok =false;
    if(s[0][0]=='#' && s[0][1]=='.' && s[1][0]=='.' && s[1][1]=='#') ok =false;
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}