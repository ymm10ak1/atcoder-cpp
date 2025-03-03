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
    int n, m, L;
    cin >> n >> m >> L;
    vector<P> a(n), b(m);
    rep(i,n){ cin >> a[i].first; a[i].second = i; }
    rep(i,m){ cin >> b[i].first; b[i].second = i; }
    map<int,set<int>> mp;
    rep(i,L){
        int c, d;
        cin >> c >> d;
        c--; d--;
        mp[c].insert(d);
    }
    sort(rall(a));
    sort(all(b));
    int mx = 0, ans = 0;
    int r = 0, idx = 0;
    rep(l,n){
        auto [ap, ai] = a[l];
        if(mx > ap+b[m-1].first) continue;
        while(r < m){
            auto [bp, bi] = b[r];
            if(mx<ap+bp && mp[ai].count(bi)==0){
                mx = ap+bp;
                idx = r;
            }
            r++;
        }
        r = idx;
        // while(r < idx){
        //     auto [bp, bi] = b[r];
        //     if(mp[ai].count(bi)==0){
        //         mx = ap+bp;
        //         idx = r;
        //         break;
        //     }
        //     r++;
        // }
        // r = 0;
        ans = max(ans, mx);
    }
    cout << ans << el;
    return 0;
}
