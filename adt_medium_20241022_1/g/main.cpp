// G
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
    int n;
    ll t;
    string s;
    cin >> n >> t >> s;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    vector<ll> one, zero;
    rep(i,n){
        x[i] *= 2;
        if(s[i] == '1') one.push_back(x[i]);
        else{
            zero.push_back(x[i]);
            zero.push_back(x[i]-2*t);
        }
    }
    sort(all(zero));
    sort(all(one));
    ll ans = 0;
    rep(i,one.size()){
        int idx1 = upper_bound(all(zero),one[i])-zero.begin();
        int idx2 = upper_bound(all(zero),one[i]+2*t)-zero.begin();
        ans += idx2-idx1;
    }
    cout << ans << el;
    return 0;
}
