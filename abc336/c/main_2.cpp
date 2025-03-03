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
    ll n; cin >> n;
    n--;
    string ans = "";
    if(n == 0) ans = '0';
    while(n){
        char c = n%5+'0';
        ans += c;
        n/=5;
    }
    reverse(all(ans));
    rep(i,ans.size()){
        if(ans[i] == '1') ans[i] = '2';
        else if(ans[i] == '2') ans[i] = '4';
        else if(ans[i] == '3') ans[i] = '6';
        else if(ans[i] == '4') ans[i] = '8';
    }
    cout << ans << el;
    return 0;
}
