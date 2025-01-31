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
    int a, b, c;
    cin >> a >> b >> c;
    bool ok = false;
    if(a+b == c) ok = true;
    if(a+c == b) ok = true;
    if(b+c == a) ok = true;
    if(a == b && b == c) ok = true;
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
