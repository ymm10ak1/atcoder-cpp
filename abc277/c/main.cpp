// C - Ladder Takahashi
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
    map<int, vector<int>> g;
    rep(i,n){
        int a, b; cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    map<int, bool> used;
    queue<int> q;
    q.push(0);
    int ans = 0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(used[now]) continue;
        used[now] = true;
        ans = max(ans, now);
        for(int nxt : g[now]){
            if(used[nxt]) continue;
            q.push(nxt);
        }
    }
    ++ans;
    cout << ans << el;
    return 0;
}
