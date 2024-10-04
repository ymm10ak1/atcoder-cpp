// C - Remembering the Days
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

// NOTE: 解説放送では再帰で実装していた
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n,vector<int>(n,-1));
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        g[a][b] = c;
        g[b][a] = c;
    }
    vector<int> a(n);
    rep(i,n) a[i] = i;
    int ans = 0;
    do{
        int sum = 0;
        rep(i,n-1){
            if(g[a[i]][a[i+1]] == -1) break;
            sum += g[a[i]][a[i+1]];
        }
        ans = max(ans, sum);
    }while(next_permutation(all(a)));
    cout << ans << el;
    return 0;
}
