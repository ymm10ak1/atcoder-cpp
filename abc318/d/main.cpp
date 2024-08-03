// D - General Weighted Max Matching
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

template<typename T>
void chmax(T& a, T b){
    if(a < b) a = b;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> d(n,vector<int>(n));
    vector<vector<int>> g(n);
    int m = n-1;
    rep(i,n){
        rep(j,m){
            int di; cin >> di;
            d[i][i+j+1] = di;
            g[i].push_back(i+j+1);
        }
        --m;
    }
    vector<ll> dp((1<<n), 0);
    rep(s,(1<<n)){
        int cnt = 0;
        rep(i,n) if((s>>i) & 1) ++cnt;
        // bit集合(0以外)のなかで1が奇数個の場合はスキップ
        if(s!=0 && cnt%2) continue;
        rep(i,n){
            // bit集合の中の0を2つを1にする
            // まだ辺が結ばれていない頂点を2つ選び辺を結ぶ
            if(((s>>i) & 1) == 0){
                for(int j : g[i]){
                    if((s>>j) & 1) continue;
                    chmax(dp[s | (1<<j) | (1<<i)], dp[s]+d[i][j]);
                }
            }
        }
    }
    ll ans = 0;
    rep(i,(1<<n)) ans = max(ans, dp[i]);
    cout << ans << el;
    return 0;
}
