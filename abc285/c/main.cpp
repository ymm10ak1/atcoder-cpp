// C abc285_brutmhyhiizp
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
    string s; cin >> s;
    int n = s.size();
    vector<ll> v;
    rep(i,n){
        ll x = 1;
        rep(j,i) x *= 26;
        v.push_back(x);
    }
    int len = 0;
    ll ans = 0;
    while(!s.empty()){
        int d = s.back()-'A'+1;
        ans += v[len]*d;
        len++;
        s.pop_back();
    }
    cout << ans << el;
    return 0;
}
