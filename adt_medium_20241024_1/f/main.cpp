// F
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
    ll n; cin >> n;
    string ans = "";
    if(n%2){
        ans += "A";
        n--;
    }
    while(n > 1){
        if(n%2){
            ans += "A";
            n--;
        }else{
            ans += "B";
            n /= 2;
        }
    }
    if(n%2 == 1) ans += "A";
    reverse(all(ans));
    cout << ans << el;
    return 0;
}
