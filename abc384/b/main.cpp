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
    int n, r;
    cin >> n >> r;
    vector<int> d(n), a(n);
    rep(i,n) cin >> d[i] >> a[i];
    rep(i,n){
        if(d[i]==1 && (1600<=r && r<2800)){
            r += a[i];
        }else if(d[i]==2 && (1200<=r && r<2400)){
            r += a[i];
        }
    }
    cout << r << el;
    return 0;
}
