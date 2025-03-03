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
    ll n, p;
    cin >> n >> p;
    vector<pair<ll,ll>> pf;
    ll scnt = 0;
    for(ll i=2; i*i<=p; ++i){
        if(p%i == 0){
            int cnt = 0;
            while(p%i == 0){
                cnt++;
                p /= i;
            }
            pf.emplace_back(i,cnt);
            scnt += cnt;
        }
    }
    if(p > 1) pf.emplace_back(p,1);
    ll gcd = 1;
    if(scnt >= n){
        for(auto [pri, cnt] : pf){
            if(cnt < n) continue;
            rep(i,cnt/n) gcd *= pri;
        }
    }
    cout << gcd << el;
    return 0;
}
