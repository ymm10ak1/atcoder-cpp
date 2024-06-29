// C - Grand Garden
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int minh = INF;
    rep(i,n) if(h[i] != 0) minh = min(minh, h[i]);
    int ans = 0;
    while(true){
        rep(i,n){
            if(i<n-1 && h[i]>=1 && h[i+1]==0) ans += minh;
            if(i==n-1 && h[n-1]>=1) ans += minh;
            if(h[i]-minh >= 0) h[i] -= minh;
        }
        int zerocnt = 0;
        minh = INF;
        rep(i,n){
            if(h[i] != 0) minh = min(minh, h[i]);
            else zerocnt++;
        }
        if(zerocnt == n) break;
    }
    cout << ans << el;
    return 0;
}
