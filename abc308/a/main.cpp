// 
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
    int s[8];
    rep(i,8) cin >> s[i];
    bool ok = true;
    rep(i,8){
        if(i<7 && s[i]>s[i+1]) ok = false;
        if(s[i]<100 || s[i]>675) ok = false;
        if(s[i]%25 != 0) ok = false;
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
