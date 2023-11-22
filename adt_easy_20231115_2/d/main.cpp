// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i = n-1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, n) sort(all(g[i]));
    rep(i, n){
        if(g[i].size() == 0) cout << 0 << el;
        else cout << g[i].size() << " ";
        rep(j, g[i].size()){
            printf("%d%c", g[i][j]+1, j==g[i].size()-1?'\n':' ');
        }
    }
    return 0;
}