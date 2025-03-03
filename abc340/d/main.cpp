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
using PL = pair<ll, int>;

// NOTE: 自力で解けていない(ダイクストラ法で解けることを知った)
int main(){
    int n; cin >> n;
    vector<vector<P>> g(n);
    rep(i,n-1){
        int a, b, x;
        cin >> a >> b >> x;
        x--;
        g[i].emplace_back(a,i+1);
        g[i].emplace_back(b,x);
    }
    priority_queue<PL,vector<PL>,greater<PL>> q;
    vector<ll> dist(n,LLINF);
    vector<bool> kakutei(n);
    dist[0] = 0;
    q.emplace(dist[0],0);
    while(!q.empty()){
        auto [costv, v] = q.top(); q.pop();
        if(kakutei[v]) continue;
        kakutei[v] = true;
        for(auto [costu, u] : g[v]){
            if(kakutei[u]) continue;
            if(dist[u] > costv+costu){
                dist[u] = costv+costu;
                q.emplace(dist[u],u);
            }
        }
    }
    cout << dist[n-1] << el;
    return 0;
}
