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
    ll b; cin >> b;
    repi(i,1,16){
        ll a = 1;
        repi(j,1,i+1){
            a *= i;
        }
        if(a == b){
            cout << i << el;
            return 0;
        }
    }
    cout << -1 << el;
    return 0;
}