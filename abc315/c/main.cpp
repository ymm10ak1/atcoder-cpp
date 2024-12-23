// C - Flavors
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
    vector<int> f(n), s(n);
    rep(i,n) cin >> f[i] >> s[i];
    priority_queue<pair<int,int>> q;
    rep(i,n) q.push({s[i],f[i]});
    ll ans = 0;
    int t = 0, fla = 0;
    bool first = true;
    while(!q.empty()){
        if(first){
            t = q.top().first;
            fla = q.top().second;
            first = false;
        }else{
            int v = 0;
            if(fla == q.top().second) v = q.top().first/2;
            else v = q.top().first;
            ans = max(ans,(ll)t+v);
        }
        q.pop();
    }
    cout << ans << el;
    return 0;
}
