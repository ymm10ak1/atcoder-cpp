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
    int n, d;
    ll p;
    cin >> n >> d >> p;
    vector<int> f(n);
    rep(i,n) cin >> f[i];
    priority_queue<P> q;
    ll  ans = 0;
    rep(i,n){
        q.emplace(f[i],i);
        ans += f[i];
    }
    while(!q.empty()){
        int cnt = 0;
        ll now = 0, fs = 0;
        while(q.size() && cnt++<d){
            now += q.top().first;
            fs += f[q.top().second];
            q.pop();
        }
        if(p < now){
            ans += p;
            ans -= fs;
        }else{
            break;
        }
    }
    cout << ans << el;
    return 0;
}
