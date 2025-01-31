#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<P> ans;
    rep(i,n-8)rep(j,m-8){
        bool ok = true;
        repi(k,i,i+9){
            repi(l,j,j+9){
                if(k-i<3 && l-j<3 && s[k][l]=='.') ok = false;
                if(k-i==3 && l-j<=3 && s[k][l]=='#') ok = false;
                if(k-i<=3 && l-j==3 && s[k][l]=='#') ok = false;
                if(k-i>=6 && l-j>=6 && s[k][l]=='.') ok = false;
                if(k-i==5 && l-j>=5 && s[k][l]=='#') ok = false;
                if(k-i>=5 && l-j==5 && s[k][l]=='#') ok = false;
            }
        }
        if(ok) ans.emplace_back(i+1,j+1);
    }
    sort(all(ans));
    rep(i,ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
