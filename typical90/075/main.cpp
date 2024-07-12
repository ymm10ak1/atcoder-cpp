//  075 - Magic For Balls（★3）
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

ll countPrime(ll n){
    ll cnt = 0, nn = n;
    for(ll i=2; i*i<=n; ++i){
        while(nn%i == 0){
            nn /= i;
            cnt++;
        }
        if(nn == 1) return cnt;
    }
    if(nn == n) return 0;
    return cnt+1;
}

int main(){
    ll n; cin >> n;
    ll pcnt = countPrime(n);
    ll p = 1, cnt = 0;
    while(p < pcnt){
        cnt++;
        p *= 2;
    }
    ll ans = cnt;
    cout << ans << el;
    return 0;
}