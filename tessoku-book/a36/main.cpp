// A36 - Travel
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
    ll n, k;
    cin >> n >> k;
    ll n2 = n*2-2;
    if(k < n2) cout << "No" << el;
    else if((k-n2)%2==1) cout << "No" << el;
    else cout << "Yes" << el;
    return 0;
}