// D - String Bags
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
    string t;
    int n;
    cin >> t >> n;
    vector<int> a(n);
    vector<vector<string>> s(n);
    int max_a=0;
    rep(i,n){
        cin >> a[i];
        max_a = max(max_a, a[i]);
        rep(j,a[i]){
            string si; cin >> si;
            s[i].push_back(si);
        }
    }
    // 文字列tより、部分文字列t0,t0t1,t0t1t2,...t0t1~t(n-1)を作成する
    string tt = "";
    vector<string> vs;
    map<string, bool> mp;
    vs.push_back(tt);
    mp[tt] = true;
    rep(i,t.size()){
        tt += t[i];
        vs.push_back(tt);
        mp[tt] = true;
    }
    // i番目の袋までで文字列jを選んで作成できる文字列kでかかる最小の金額
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(max_a+1, vector<int>(t.size()+1,INF)));
    dp[0][0][0] = 0;
    rep(i,n){
        rep(j,max_a+1){
            rep(k,t.size()+1){
                if(dp[i][j][k] != INF){
                    rep(l,a[i]+1){
                        string tt;
                        int mo = 0;
                        if(l > 0){
                            tt = vs[k]+s[i][l-1];
                            mo = 1;
                        }else{
                            tt = vs[k];
                        }
                        if(!mp[tt]) continue;
                        int ttsize = (int)tt.size();
                        dp[i+1][l][ttsize] = min(dp[i+1][l][ttsize],dp[i][j][k]+mo);
                    }
                }
            }
        }
    }
    int ans = INF;
    rep(i,max_a+1) ans = min(ans, dp[n][i][(int)(t.size())]);
    cout << (ans == INF ? -1 : ans) << el;
    return 0;
}