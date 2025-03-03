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

// 自力でACできていない
int main(){
    ll w, h, x, y;
    cin >> w >> h >> x >> y;
    // (x,y)と対角線の交点を通るような直線を引けば2つの面積は等しい
    // 長方形の半分が面積の最大値である
    long double ans = (long double)h*w/2;
    int check = 0;
    if(w%2==0 && h%2==0 && w/2==x && h/2==y) check = 1;
    printf("%Lf %d\n", ans, check);
    return 0;
}
