#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    // BUG: WA 解法が間違っている
    if(n%2){
        int d = 1, l = 0;
        rep(i,n/2){
            if(n-1-i>=0 && (a[i]<d || a[n-1-i]<d)) l = i;
            d++;
        }
        d = n/2-l+1;
        if(a[n/2] >= d) ans = d;
        else ans = --d;
    }else{
        int d1 = 1, d2 = 1;
        int l1 = 0, l2 = 0;
        rep(i,n/2){
            if(n-2-i>=0 && (a[i]<d1 || a[n-2-i]<d1)) l1 = i;
            if(n-(i+1)>=0 && (a[i+1]<d2 || a[n-(i+1)]<d2)) l2 = i;
            d1++; d2++;
        }
        d1 = n/2-l1+1;
        d2 = n/2-l2+1;
        if(a[n/2] >= d1) ans = d1;
        else ans = --d1;
        if(a[n/2+1] >= d2) ans = max(ans, d2);
        else ans = max(ans, --d2);
    }
    cout << ans << el;
    return 0;
}
