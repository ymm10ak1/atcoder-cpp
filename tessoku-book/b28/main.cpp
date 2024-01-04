// B28 - Fibonacci Easy (mod 1000000007)
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

const int MOD = 1000000007;

int main(){
    int n; cin >> n;
    vector<ll> fibo(n);
    fibo[0] = 1, fibo[1] = 1;
    repi(i, 2, n){
        fibo[i] = fibo[i-1]+fibo[i-2];
        fibo[i] %= MOD;
    }
    cout << fibo[n-1] << el;
    return 0;
}