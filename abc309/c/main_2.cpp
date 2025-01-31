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

int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    ll sum = 0;
    rep(i,n){
        sum += b[i];
        q.emplace(a[i],b[i]);
    }
    ll ans = 0;
    while(!q.empty()){
        if(sum <= k){
            cout << ans+1 << el;
            return 0;
        }
        auto now = q.top(); q.pop();
        ans = now.first;
        sum -= now.second;
    }
    if(sum <= k) cout << ans+1 << el;
    return 0;
}
