// E - King Bombee
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

constexpr int M = 998244353;

int main(){
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    vector<vector<int>> g(n);
    rep(i,m){
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    --s; --t; --x;
    // dp[i][j]: Aのk項目で前の項と繋がっている頂点iを選び、それまでにxが出た回数を2で割った余りがjのときの個数
    vector<vector<int>> dp(n,vector<int>(2,0));
    dp[s][0] = 1;
    rep(i,k){
        // 遷移先のdpを用意する
        vector<vector<int>> p(n,vector<int>(2,0));
        rep(j,n){
            rep(l,2){
                if(dp[j][l] >= 1){
                    for(int nxt : g[j]){
                        if(i==k-1 && nxt==t){
                            p[nxt][l] = (p[nxt][l]+dp[j][l])%M;
                        }else if(i < k-1){
                            if(nxt == x) p[nxt][(l+1)%2] = (p[nxt][(l+1)%2]+dp[j][l])%M;
                            else p[nxt][l] = (p[nxt][l]+dp[j][l])%M;
                        }
                    }
                }
            }
        }
        // 遷移先のdpと遷移元のdpを入れ替える
        swap(p, dp);
    }
    cout << dp[t][0] << el;
    return 0;
}