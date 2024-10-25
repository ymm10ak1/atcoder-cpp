// C - Max Even
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
    sort(rall(a));
    int even = 0, odds = 0;
    int cnte = 0, cnto = 0;
    int ans = -1;
    rep(i,n){
        if(a[i]%2 == 0){
            if(cnte < 2) even += a[i];
            cnte++;
            if(cnte == 2) ans = max(ans, even);
        }else{
            if(cnto < 2) odds += a[i];
            cnto++;
            if(cnto == 2) ans = max(ans, odds);
        }
    }
    cout << ans << el;
    return 0;
}
