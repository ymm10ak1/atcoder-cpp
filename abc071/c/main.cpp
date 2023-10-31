// C - Make a Rectangle
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(rall(a));
    map<int, int> mp;
    rep(i, n) mp[a[i]]++;
    int rect = 0;
    ll ans = 1;
    rep(i, n){
        if(mp[a[i]] >= 4){
            if(rect == 1){
                ans *= a[i];
                rect++;
            }else{
                rect += 2;
                ans = (ll)a[i]*a[i];
            }
        }else if(mp[a[i]]>=2 && mp[a[i]]<4){
            rect++;
            ans *= a[i];
            mp.erase(a[i]);
        }
        if(rect == 2){
            cout << ans << el;
            return 0;
        }
    }
    cout << 0 << el;
    return 0;
}