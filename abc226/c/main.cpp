// C - Martial artist
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
    int n; cin >> n;
    vector<int> t(n), k(n);
    vector<vector<int>> g(n);
    rep(i,n){
        cin >> t[i] >> k[i];
        rep(j,k[i]){
            int ai; cin >> ai;
            --ai;
            g[i].push_back(ai);
        }
    }
    queue<int> q;
    vector<bool> used(n);
    q.push(n-1);
    ll ans = 0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(used[now]) continue;
        used[now] = true;
        ans += t[now];
        for(int nxt : g[now]){
            if(used[nxt]) continue;
            q.push(nxt);
        }
    }
    cout << ans << el;
    return 0;
}
