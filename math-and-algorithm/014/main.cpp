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
    ll m = n;
    vector<ll> ans;
    for(ll i=2; i*i<=n; ++i){
        // ここの素数判定いらない
        // 2で割れるところまで割り、3で割れるところまで割り、5で ...
        // という感じですれば2の倍数、3の倍数といった合成数が残らないので素数で割っていることになる
        bool isPrime = true;
        for(ll j=2; j*j<=i; ++j) if(i%j == 0) isPrime = false;
        if(isPrime){
            while(m>1 && m%i==0){
                ans.push_back(i);
                m /= i;
            }
        }
    }
    if(m > 1LL) ans.push_back(m);
    sort(all(ans));
    rep(i,ans.size()) printf("%lld%c", ans[i], i==(int)ans.size()-1?'\n':' ');
    return 0;
}
