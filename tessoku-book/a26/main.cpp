// A26 - Prime Check
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

bool isPrime(ll x){
    for(ll i=2; i*i<=x; ++i){
        if(x%i == 0) return false;
    }
    return true;
}

int main(){
    int q;
    cin >> q;
    rep(i, q){
        ll x; cin >> x;
        string ans = isPrime(x)?"Yes":"No";
        cout << ans << el;
    }
    return 0;
}