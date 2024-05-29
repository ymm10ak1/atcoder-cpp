// D - Banned K
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

int cnt[200005];
bool check[200005];

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        ++cnt[a[i]];
    }
    ll sum = 0;
    rep(i,n){
        if(!check[a[i]]) sum += (ll)cnt[a[i]]*(cnt[a[i]]-1)/2;
        check[a[i]] = true;
    }
    rep(i,n){
        ll v = sum;
        v -= (ll)cnt[a[i]]*(cnt[a[i]]-1)/2;
        v += (ll)(cnt[a[i]]-1)*(cnt[a[i]]-2)/2;
        cout << v << el;
    }
    return 0;
}
