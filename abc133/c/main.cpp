// C - Remainder Minimization 2019
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

constexpr int M = 2019;

int main(){
    int l, r;
    cin >> l >> r;
    int ld = l/M, rd = r/M;
    if(ld < rd){
        cout << 0 << el;
    }else if(ld == rd){
        int lr = l%M, rr = r%M;
        int ans = INF;
        repi(i,lr,rr) repi(j,lr+1,rr+1) ans = min(ans, i*j%M);
        cout << ans << el;
    }
    return 0;
}
