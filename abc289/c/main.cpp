// C - Coverage
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
    vector<vector<int>> S(m);
    rep(i,m){
        int c; cin >> c;
        rep(j,c){
            int ai; cin >> ai;
            --ai;
            S[i].push_back(ai);
        }
    }
    int ans = 0;
    rep(s,(1<<m)){
        vector<int> sele;
        rep(i,m) if((s>>i) & 1) sele.push_back(i);
        // NOTE: 解説見ると1<=x<=Nがすべて含まれているかのチェックをstd::setで行っている
        // 選ばれた集合の整数をsetに格納してそのサイズがNでなければカウントしないようにしている
        vector<bool> check(n,false);
        rep(i,sele.size()){
            rep(j,S[sele[i]].size()) check[S[sele[i]][j]] = true;
        }
        bool ok = true;
        rep(i,n) if(!check[i]) ok = false;
        if(ok) ++ans;
    }
    cout << ans << el;
    return 0;
}
