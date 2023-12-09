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
    int a, b;
    cin >> a >> b;
    string ans = "Alloy";
    if(0<a && b==0) ans = "Gold";
    else if(a==0 && 0<b) ans = "Silver";
    else if(0<a && 0<b) ans = "Alloy";
    cout << ans << el;
    return 0;
}