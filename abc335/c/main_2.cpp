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
    int n, q;
    cin >> n >> q;
    deque<P> de;
    rep(i,n) de.emplace_back(i+1,0);
    rep(qi,q){
        int t; cin >> t;
        if(t == 1){
            char c; cin >> c;
            int nx = de[0].first, ny = de[0].second;
            if(c == 'R') nx++;
            else if(c == 'L') nx--;
            else if(c == 'U') ny++;
            else ny--;
            de.emplace_front(nx,ny);
            de.pop_back();
        }else{
            int p; cin >> p;
            printf("%d %d\n", de[p-1].first, de[p-1].second);
        }
    }
    return 0;
}
