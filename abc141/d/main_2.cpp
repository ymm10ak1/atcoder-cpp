// D - Powerful Discount Tickets
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    priority_queue<int> q;
    rep(i,n) q.push(a[i]);
    rep(i,m){
        int now = q.top(); q.pop();
        q.push(now/2);
    }
    ll sum = 0;
    while(!q.empty()){
        int now = q.top(); q.pop();
        sum += now;
    }
    cout << sum << el;
    return 0;
}
