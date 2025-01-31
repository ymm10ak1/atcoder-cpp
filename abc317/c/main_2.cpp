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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cost(n,vector<int>(n,-INF));
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        cost[a][b] = c;
        cost[b][a] = c;
    }
    vector<int> a(n);
    rep(i,n) a[i] = i;
    int ans = 0;
    do{
        int now = 0;
        rep(i,n-1){
            if(cost[a[i]][a[i+1]] == -INF) break;
            now += cost[a[i]][a[i+1]];
        }
        ans = max(ans,now);
    }while(next_permutation(all(a)));
    cout << ans << el;
    return 0;
}
