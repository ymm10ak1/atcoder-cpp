// C - Blue Spring
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
    ll p;
    cin >> n >> d >> p;
    vector<int> f(n);
    rep(i,n) cin >> f[i];
    priority_queue<int> q;
    ll ans = 0;
    rep(i,n){
        q.push(f[i]);
        ans += f[i];
    }
    while(!q.empty()){
        ll sum = 0;
        rep(i,d){
            if(q.empty()) continue;
            sum += q.top();
            q.pop();
        }
        if(p < sum){
            ans -= sum;
            ans += p;
        }else{
            break;
        }
    }
    cout << ans << el;
    return 0;
}
