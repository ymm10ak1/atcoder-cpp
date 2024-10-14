// C - Virus
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
    int n, d;
    cin >> n >> d;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<bool> ans(n);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(ans[now]) continue;
        ans[now] = true;
        rep(i,n){
            if(now == i) continue;
            if(ans[i]) continue;
            int dist = (x[now]-x[i])*(x[now]-x[i])+(y[now]-y[i])*(y[now]-y[i]);
            if(dist <= d*d) q.push(i);
        }
    }
    for(bool b : ans){
        if(b) cout << "Yes" << el;
        else cout << "No" << el;
    }
    return 0;
}
