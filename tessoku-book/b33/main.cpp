// B33 - Game 6
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
    int n, h, w;
    cin >> n >> h >> w;
    vector<int> a(n), b(n);
    rep(i, n){
        cin >> a[i] >> b[i];
        --a[i]; --b[i];
    }
    int xor_sum = a[0]^b[0];
    repi(i, 1, n) xor_sum = xor_sum^(a[i]^b[i]);
    if(xor_sum == 0) cout << "Second" << el;
    else cout << "First" << el;
    return 0;
}