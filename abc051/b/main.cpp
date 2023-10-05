// B - Sum of Three Integers
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define REPI(i, s, n) for(int i=(int)(s); i<=(int)(n); ++i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0, n)
#define REPL(i, s, n) for(ll i=(s); i<=(ll)(n); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    int k, s;
    cin >> k >> s;
    int cnt = 0;
    REPI(x, 0, k){
        REPI(y, 0, k){
            int v = s-x-y;
            if(v >= 0 && v <= k) ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}