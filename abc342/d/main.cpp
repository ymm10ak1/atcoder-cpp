#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n){
        ll ai = a[i];
        for(ll j=2; j*j<=a[i]; j++){
            if(a[i]%j != 0) continue;
            int cnt = 0;
            ll d = 1;
            while(ai%j == 0){
                cnt++;
                ai /= j;
                d *= j;
            } 
            if(cnt%2) d /= j;
            a[i] /= d;
        }
    }
    map<ll,int> mp;
    rep(i,n) mp[a[i]]++;
    ll ans = 0;
    rep(i,n){
        if(mp[a[i]] > 0) mp[a[i]]--;
        if(a[i] == 0){
            ans += (n-i-1);
        }else{
            ans += mp[a[i]];
            ans += mp[0];
        }
    }
    cout << ans << el;
    return 0;
}
