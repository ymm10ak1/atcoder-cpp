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

int jogging(int s, int r, int x){
    int p = 0;
    while(x > 0){
        p += min(x, s);
        x -= min(x, s);
        if(x <= 0) break;
        x -= r;
    }
    return p;
}

int main(){
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;
    int takahashi = jogging(a, c, x);
    int aoki = jogging(d, f, x);
    takahashi *= b; aoki *= e;
    if(takahashi > aoki) cout << "Takahashi" << el;
    else if(takahashi < aoki) cout << "Aoki" << el;
    else cout << "Draw" << el;
    return 0;
}