// C - Connect Cities
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

// NOTE: 解説見るとグラフの連結成分の数-1で求められる
int main(){
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    int v = -1;
    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a; --b;
        if(v == -1) v = a;
        uf.merge(a,b);
    }
    int ans = 0;
    rep(i,n){
        if(!uf.same(v,i)){
            uf.merge(v,i);
            ans++;
        }
    }
    cout << ans << el;
    return 0;
}
