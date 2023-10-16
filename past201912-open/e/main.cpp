// E - SNSのログ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> c(n, vector<int>(n, 0));
    rep(i, q){
        int s, a;
        cin >> s >> a;
        a--;
        if(s == 1){
            int b; cin >> b;
            b--;
            c[a][b] = 1;
        }else if(s == 2){
            rep(j, n){
                if(c[j][a] == 1) c[a][j] = 1;
            }
        }else{
            vector<bool> cnt(n, false);
            // aがフォローしているユーザーの確認
            rep(j, c[a].size()){
                if(c[a][j] == 1) cnt[j] = true;
            }
            // aがフォローしているユーザーがフォローしているユーザーをフォローする(a自身をのぞく)
            rep(j, n){
                rep(k, c[j].size()){
                    if(!cnt[j]) break;
                    if(k != a && c[j][k] == 1) c[a][k] = 1;
                }
            }
        }
    }
    rep(i, n) rep(j, n){
        if(c[i][j] == 1) cout << "Y";
        else cout << "N";
        if(j == n-1) cout << el;
    }
    return 0;
}