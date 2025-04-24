#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    ll x; int k;
    cin >> x >> k;
    string ans = "";
    rep(i,k){
        if(x%10 < 5) x -= x%10;
        else x += (10-x%10);
        ll nd = x%10;
        ans += nd+'0';
        x /= 10;
    }
    while(x){
        ll d = x%10;
        x /= 10;
        ans += d+'0';
    }
    reverse(all(ans));
    if(ans[0] == '0') ans = '0';
    cout << ans << el;
    return 0;
}
