#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    double t, l, x, y, q;
    cin >> t >> l >> x >> y >> q;
    vector<double> e(q);
    rep(i,q) cin >> e[i];

    auto f = [&](double e){
        double theta = e/t*M_PI*2;
        double y2 = -(l/2)*sin(theta);
        double z = (l/2)-(l/2)*cos(theta);
        double a = sqrt(x*x+(y-y2)*(y-y2));
        return atan2(z, a)*180.0/M_PI;
    };

    rep(i,q) printf("%.12f\n", f(e[i]));
    return 0;
}
