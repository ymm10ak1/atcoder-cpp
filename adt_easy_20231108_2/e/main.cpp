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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = (1<<30);
    rep(bit, (1<<(n-1))){
        int xor_a = 0, or_a = a[0];
        rep(i, n-1){
            if(bit&(1<<i)){
                xor_a ^= or_a;
                or_a = 0;
            }
            or_a |= a[i+1];
        }
        xor_a ^= or_a;
        ans = min(ans, xor_a);
    }
    cout << ans << el;
    return 0;
}