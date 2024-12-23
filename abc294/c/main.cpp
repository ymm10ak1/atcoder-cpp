// C - Merge Sequences
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
    int n, m;
    cin >> n >> m;
    vector<pair<int,char>> c;
    rep(i,n){
        int ai; cin >> ai;
        c.emplace_back(ai,'a');
    }
    rep(i,m){
        int bi; cin >> bi;
        c.emplace_back(bi,'b');
    }
    sort(all(c));
    vector<int> a, b;
    rep(i,c.size()){
        if(c[i].second == 'a') a.push_back(i+1);
        else if(c[i].second == 'b') b.push_back(i+1);
    }
    rep(i,a.size()) printf("%d%c", a[i], i==(int)a.size()-1?'\n':' ');
    rep(i,b.size()) printf("%d%c", b[i], i==(int)b.size()-1?'\n':' ');
    return 0;
}
