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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll cnt1 = 0, cnt2 = 0;
    rep(i,n){
        if(i+1 == a[i]) ++cnt2;
        else if(i+1 == a[a[i]-1]) ++cnt1;
    }
    ll ans = (cnt1/2)+(cnt2*(cnt2-1)/2);
    cout << ans << el;
    return 0;
}