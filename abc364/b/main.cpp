// template {{{
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
// }}}

int main(){
    int h, w, si, sj;
    cin >> h >> w >> si >> sj;
    si--; sj--;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    string x; cin >> x;
    rep(i,x.size()){
        if(x[i] == 'L'){
            if(sj-1 < 0) continue;
            if(c[si][sj-1] == '#') continue;
            sj--;
        }else if(x[i] == 'R'){
            if(sj+1 >= w) continue;
            if(c[si][sj+1] == '#') continue;
            sj++;
        }else if(x[i] == 'U'){
            if(si-1 < 0) continue;
            if(c[si-1][sj] == '#') continue;
            si--;
        }else{
            if(si+1 >= h) continue;
            if(c[si+1][sj] == '#') continue;
            si++;
        }
    }
    printf("%d %d\n", si+1, sj+1);
    return 0;
}
