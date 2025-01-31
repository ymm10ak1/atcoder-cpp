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

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i] >> d[i];
    int maxx = 0, maxy = 0;
    rep(i,n){
        maxx = max({maxx, a[i], b[i]});
        maxy = max({maxy, c[i], d[i]});
    }
    int area = 0;
    rep(i,maxx){
        rep(j,maxy){
            bool ok = false;
            rep(k,n) if((a[k]<=i && i<b[k]) && (c[k]<=j && j<d[k])) ok = true;
            if(ok) area++;
        }
    }
    cout << area << el;
    return 0;
}
