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

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    rep(i,n) d[i] %= (a+b);
    sort(all(d));
    vector<int> e;
    int mx = 0;
    rep(i,n){
        if(i < n-1){
            e.push_back(d[i+1]-d[i]);
            mx = max(mx, d[i+1]-d[i]);
        }else{
            e.push_back(d[0]+(a+b)-d[i]);
            mx = max(mx, d[0]+(a+b)-d[i]);
        }
    } 
    ll dist = 0;
    bool first = false;
    // NOTE: 解説より隣あった2つの距離の差がb+1以上あれば全ての予定を休日にすることが可能
    rep(i,e.size()){
        if(!first && e[i]==mx){ first = true; continue; }
        dist += e[i];
    }
    bool ok = true;
    if(dist >= a) ok = false;
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
