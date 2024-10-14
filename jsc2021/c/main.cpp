// C - Max GCD 2
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

void divisor(ll n, map<ll,int>& mp){
    for(ll i=1; i*i<=n; ++i){
        if(n%i == 0){
            mp[i]++;
            if(n/i != i) mp[n/i]++;
        }
    }
}

int main(){
    ll a, b;
    cin >> a >> b;
    map<ll,int> mp;
    for(ll i=a; i<=b; ++i) divisor(i,mp);
    for(ll i=b; i>=1; --i){
        if(mp[i] >= 2){
            cout << i << el;
            return 0;
        }
    }
    return 0;
}
