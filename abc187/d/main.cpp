// D - Choose Me
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
using P = pair<int,int>;

// BUG: WA解(aで高い順、a+bで高い順でするのはダメ)
int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    priority_queue<P> q;
    rep(i,n){
        q.emplace(a[i],i);
        q.emplace(b[i],i);
    }
    ll aoki = 0;
    rep(i,n) aoki += a[i];
    ll takahashi = 0;
    vector<bool> used(n);
    int ans = 0;
    while(!q.empty()){
        P now = q.top(); q.pop();
        if(used[now.second]) continue;
        used[now.second] = true;
        takahashi += a[now.second]+b[now.second];
        aoki -= a[now.second];
        ans++;
        if(takahashi > aoki){
            cout << ans << el;
            return 0;
        }
    }
    return 0;
}
