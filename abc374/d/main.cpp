// D
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
    int n, s, t; 
    cin >> n >> s >> t;
    vector<int> a(n), b(n), c(n), d(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<int> v(n);
    rep(i,n) v[i] = i;
    const ll EPS = 1e-14;
    long double ans = 1e9;
    // NOTE: 解説AC
    // n!回探索する考えまではよかったけど、今いる点から近い点を試すのではなくて
    // n<=6より、bit全探索で1なら(a[i],b[i])から、0なら(c[i],d[i])から線分を引くという方法を全て試せばいい
    // 計算量はO(n!*n*2^n)で間に合う
    do{
        rep(bit,(1<<n)){
            pair<int,int> p = {0,0};
            vector<pair<int,int>> dis;
            rep(i,n){
                int dx = 0, dy = 0;
                if((bit>>i) & 1){
                    dx = (p.first-a[v[i]])*(p.first-a[v[i]]);
                    dy = (p.second-b[v[i]])*(p.second-b[v[i]]);
                    p = {c[v[i]],d[v[i]]};
                }else{
                    dx = (p.first-c[v[i]])*(p.first-c[v[i]]);
                    dy = (p.second-d[v[i]])*(p.second-d[v[i]]);
                    p = {a[v[i]],b[v[i]]};
                }
                int ac = (a[v[i]]-c[v[i]])*(a[v[i]]-c[v[i]]);
                int bd = (b[v[i]]-d[v[i]])*(b[v[i]]-d[v[i]]);
                dis.emplace_back(dx+dy,s);
                dis.emplace_back(ac+bd,t);
            }
            long double sum = 0;
            rep(i,dis.size()){
                long double dd = sqrt((long double)dis[i].first)/dis[i].second;
                dd += EPS;
                sum += dd;
                sum += EPS;
            }
            ans = min(ans, sum);
        }
    }while(next_permutation(all(v)));
    printf("%.20Lf\n",ans);
    return 0;
}
