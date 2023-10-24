// C - Same Integers
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
    int a[3];
    rep(i, 3) cin >> a[i];
    sort(a, a+3);
    vector<bool> even(3, false);
    int even_cnt = 0;
    rep(i, 3){
        if(a[i]%2 == 0){
            even[i] = true;
            even_cnt++;
        }
    }
    int ans = 0;
    if(even_cnt == 1){
        ans += 1;
        rep(i, 3) if(!even[i]) a[i]++; 
    }else if(even_cnt == 2){
        ans += 1;
        rep(i, 3) if(even[i]) a[i]++;
    }
    ans += (a[2]-a[1])/2;
    ans += (a[2]-a[0])/2;
    cout << ans << el;
    return 0;
}