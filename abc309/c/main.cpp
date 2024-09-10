// C - Medicine
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
    ll sum = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    rep(i,n){
        sum += b[i];
        q.push({a[i], b[i]});
    }
    int ans = 0;
    while(!q.empty()){
        if(sum <= k){
            cout << ans+1 << el;
            return 0;
        }
        auto p = q.top(); q.pop();
        sum -= p.second;
        ans = p.first;
    }
    cout << ans+1 << el;
    return 0;
}
