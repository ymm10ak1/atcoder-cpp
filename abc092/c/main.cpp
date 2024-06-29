// C - Traveling Plan
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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int sum = abs(a[0]);
    rep(i,n){
        if(i < n-1) sum += abs(a[i+1]-a[i]);
        else sum += abs(a[i]);
    }
    rep(i,n){
        int ans = sum;
        if(i == 0){
            ans -= abs(a[i])+abs(a[i+1]-a[i]);
            ans += abs(a[i+1]);
        }else if(i>0 && i<n-1){
            ans -= abs(a[i]-a[i-1])+abs(a[i+1]-a[i]);
            ans += abs(a[i+1]-a[i-1]);
        }else{
            ans -= abs(a[i])+abs(a[i]-a[i-1]);
            ans += abs(a[i-1]);
        }
        cout << ans << el;
    }
    return 0;
}
