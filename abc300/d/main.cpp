// 
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


// BUG: 解法が思いつかないので一旦放置
int main(){
    ll n; cin >> n;
    int num = 1000000;
    vector<bool> prime(num+1,true);
    prime[1] = false;
    vector<ll> p;
    repi(i,2,num+1){
        if(!prime[i]) continue;
        for(int j=i*2; j<=num; j+=i) prime[j] = false;
        p.push_back(i);
    }
    sort(all(p));
    int m = p.size();
    cout << "m=" << m << el;
    ll ans = 0;
    set<ll> st1, st2;
    rep(a,m-2){
        repi(b,a+1,m-1) st1.insert(p[a]*p[a]*p[b]);
    }
    repi(c,2,m) st2.insert(p[c]*p[c]);
    cout << st1.size() << " " << st2.size() << el;
    cout << ans << el;
    return 0;
}
