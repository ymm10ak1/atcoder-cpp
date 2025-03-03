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

// BUG: WA
int main(){
    int n; cin >> n;
    vector<int> cnto(100005), cnte(100005);
    rep(i,n){
        int a; cin >> a;
        if(i%2) cnto[a]++;
        else cnte[a]++;
    }
    vector<P> o, e;
    rep(i,cnto.size()){
        if(cnto[i] > 0) o.emplace_back(cnto[i], i);
        if(cnte[i] > 0) e.emplace_back(cnte[i], i);
    }
    o.emplace_back(0,-1);
    e.emplace_back(0,-1);
    sort(rall(o));
    sort(rall(e));
    int ans = INF;
    rep(i,e.size()){
        rep(j,o.size()){
            if(e[i].second != o[j].second){
                ans = min(ans, (n/2-e[i].first)+(n/2-o[j].first));
                break;
            }
        }
    }
    cout << ans << el;
    return 0;
}
