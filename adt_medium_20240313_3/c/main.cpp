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
    int a, b, d;
    cin >> a >> b >> d;
    double rad = d*M_PI/180;
    double ad = a*cos(rad)-b*sin(rad);
    double bd = a*sin(rad)+b*cos(rad);
    printf("%.20f %.20f\n", ad, bd);
    return 0;
}