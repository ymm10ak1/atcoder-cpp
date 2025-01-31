#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
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
    priority_queue<P> q;
    rep(i,n) q.emplace(s[i],f[i]);
    ll m = 0, ans = 0;
    int now = 0;
    while(!q.empty()){
        auto [si,fi] = q.top(); q.pop();
        if(m == 0){
            ans = m = si;
            now = fi;
        }else{
            if(now == fi) ans = max(ans, m+si/2);
            else ans = max(ans, m+si);
        }
    }
    cout << ans << el;
    return 0;
}
