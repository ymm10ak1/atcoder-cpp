// B40 - Divide by 100
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
    vector<int> cnt(101, 0);
    rep(i, n) ++cnt[a[i]%100];
    ll ans = 0;
    rep(i, 51){
        if(i<50) ans += cnt[i]*cnt[100-i];
        if(i==0||i==50)ans += cnt[i]*(cnt[i]-1)/2;
    }
    cout << ans << el;
    return 0;
}