// 078 - Easy Graph Problem（★2）
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
    vector<vector<int>> g(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = n-1;
    repi(i,1,n){
        if(g[i].size() == 0){
            --ans;
            continue;
        }
        sort(all(g[i]));
        if(g[i].size()>1 && g[i][1]<i) --ans;
        if(g[i][0] > i) --ans;
    }
    cout << ans << el;
    return 0;
}
