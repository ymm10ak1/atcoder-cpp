// C - Keys
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(m);
    vector<vector<int>> a(m);
    vector<char> r(m);
    rep(i,m){
        cin >> c[i];
        rep(j,c[i]){
            int ai; cin >> ai;
            a[i].push_back(ai);
        }
        cin >> r[i];
    }
    int ans = 0;
    // 変数bitを2進数にしたときの各桁について 1:正しい鍵, 0:ダミーの鍵
    rep(bit,(1<<n)){
        vector<int> ke(n);
        rep(i,n){
            if(bit & (1<<i)) ke[i] = 1;
            else ke[i] = 0;
        }
        bool ok = true;
        rep(i,m){
            int cnt = 0;
            rep(j,a[i].size()) if(ke[a[i][j]-1] == 1) ++cnt;
            if(cnt>=k && r[i]!='o') ok = false;
            else if(cnt<k && r[i]!='x') ok = false;
        }
        if(ok) ++ans;
    }
    cout << ans << el;
    return 0;
}
