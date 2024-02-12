// B34 - Game 7
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<int> grundy = {0, 0, 1, 1, 2};
    ll xor_sum = 0;
    rep(i, n) xor_sum = (xor_sum^=grundy[a[i]%5]);
    if(xor_sum != 0) cout << "First" << el;
    if(xor_sum == 0) cout << "Second" << el;
    return 0;
}