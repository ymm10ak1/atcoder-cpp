// A - Sorted Arrays
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

bool inc[100005], decr[100005];

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    inc[0] = inc[n] = true;
    decr[0] = decr[n] = true;
    rep(i,n-1){
        if(a[i] <= a[i+1]) continue;
        else inc[i+1] = true;
    }
    rep(i,n-1){
        if(a[i] >= a[i+1]) continue;
        else decr[i+1] = true;
    }
    bool l1 = false, l2 = false;
    int ans = 0;
    repi(i,1,n+1){
        if(inc[i]) l1 = true;
        if(decr[i]) l2 = true;
        if(l1 && l2){
            ++ans;
            l1 = l2 = false;
        }
    }
    cout << ans << el;
    return 0;
}
