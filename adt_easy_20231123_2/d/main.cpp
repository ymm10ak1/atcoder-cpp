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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<bool> secret(n, false);
    int idx = x-1;
    while(!secret[idx]){
        secret[idx] = true;
        idx = a[idx]-1;
    }
    int ans = 0;
    rep(i, n){
        if(secret[i]) ++ans;
    }
    cout << ans << el;
    return 0;
}