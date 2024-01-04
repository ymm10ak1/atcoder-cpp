// A27 - Caluculate GCD
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

int gcd(int x, int y){
    if(x%y == 0) return y;
    return gcd(y, x%y);
}

int main(){
    int a, b;
    cin >> a >> b;
    int ans = gcd(max(a, b), min(a, b));
    cout << ans << el;
    return 0;
}