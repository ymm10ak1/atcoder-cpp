// E - Traveling Salesman among Aerial Cities
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

template <typename T>
void chmin(T& a, T b){
    if(a > b) a = b;
}

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n), z(n);
    rep(i,n) cin >> x[i] >> y[i] >> z[i];
    // dp[i][j]: 各都市を訪れた状態iの中で最後に都市jを訪れたときの最小コスト
    vector<vector<int>> dp((1<<n),vector<int>(n,INF));
    dp[0][0] = 0;
    rep(bit,(1<<n)){
        rep(i,n){
            if(bit!=0 && (bit&(1<<i))==0) continue;
            rep(j,n){
                // NOTE: bit&1<<jについて、この問題では大丈夫だがjが40のときなどにオーバーフローするので
                // 書き方としてはbit>>j&1(bitのj桁目を取り出して1かどうか確認)のほうがおすすめらしい
                if((bit&(1<<j)) == 0){
                    int cost = abs(x[j]-x[i])+abs(y[j]-y[i])+max(0,z[j]-z[i]);
                    chmin(dp[bit | (1<<j)][j], dp[bit][i]+cost);
                }
            }
        }
    }
    cout << dp[(1<<n)-1][0] << el;
    return 0;
}
