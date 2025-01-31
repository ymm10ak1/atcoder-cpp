#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n; cin >> n;
    vector<ll> s(n), c(n);
    rep(i,n) cin >> s[i] >> c[i];
    // NOTE: map<ll,ll>で実装するのでも良さそう
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    rep(i,n) q.emplace(s[i],c[i]);
    set<pair<ll,ll>> st;
    while(!q.empty()){
        auto [si,ci] = q.top(); q.pop();
        while(q.size()>=1 && si == q.top().first){
            ci += q.top().second;
            q.pop();
        }
        if(ci >= 2) q.emplace(si*2,ci/2);
        if(ci%2 == 1) st.emplace(si,ci%2);
    }
    cout << st.size() << el;
    return 0;
}
