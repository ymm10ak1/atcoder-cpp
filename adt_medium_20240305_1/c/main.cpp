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

const int m = 998244353;

int main(){
    ll n; cin >> n;
    ll x = n%m;
    // 負の数に対する余りの仕様に気づけばforで回す必要ない(負の数に対して余りを取ると負になるので0以上になるように余りを足す)
    for(int i=0; i<m+1; ++i){
        if((n-i)%m == 0){
            cout << i << el;
            return 0;
        }
    }
    return 0;
}