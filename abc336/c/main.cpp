// C - Even Digits
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

// NOTE: 5進数を作る処理で解けるみたい
int main(){
    ll n; cin >> n;
    n--;
    ll v5 = 1, v2 = 1;
    int cnt = 0;
    const ll MAX5 = 1e12;
    vector<pair<ll,int>> n5;
    map<int,ll> n2;
    while(v5 < MAX5){
        n5.emplace_back(v5,cnt);
        n2[cnt] = v2;
        cnt++;
        v5 *= 5;
        v2 *= 2;
    }
    sort(rall(n5));
    int idx = 0;
    ll ans = 0;
    while(n>0){
        if(n5[idx].first > n){
            idx++;
            continue;
        }
        n -= n5[idx].first;
        ans += n5[idx].first*n2[n5[idx].second];
    }
    ans *= 2;
    cout << ans << el;
    return 0;
}
