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
    vector<pair<int,int>> y;
    map<int,set<int>> bh;
    rep(i,m){
        int xi, yi;
        char c;
        cin >> xi >> yi >> c;
        if(c == 'B') bh[xi].insert(yi);
        else y.emplace_back(xi,yi);
    }
    bool ok = true;
    for(auto p : y){
        auto it = bh.lower_bound(p.first);
        if(it == bh.end()) continue;
        set<int> st = it->second;
        auto itt = st.lower_bound(p.second);
        if(itt == st.end()) continue;
        ok = false;
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
