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

template<typename T>
bool chmin(T& a, T b){
    if(a > b){ a = b; return true; }
    return false;
}

int main(){
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> c(n);
    vector<vector<int>> a(n,vector<int>(k));
    rep(i,n){
        cin >> c[i];
        rep(j,k) cin >> a[i][j];
    }
    int np = 0;
    rep(i,k) np = np*10+p;
    vector<vector<ll>> dp(n+1,vector<ll>(np+1,LLINF));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,np+1){
            if(dp[i][j] == LLINF) continue;
            string s = to_string(j);
            if((int)s.size() < k) s = string(k-s.size(),'0')+s;
            int nj = 0;
            rep(l,k){
                int d = a[i][l]+(s[l]-'0');
                nj = nj*10+(d>=p?p:d);
            }
            chmin(dp[i+1][j],dp[i][j]);
            chmin(dp[i+1][nj],dp[i][j]+c[i]);
        }
    }
    cout << (dp[n][np]==LLINF?-1:dp[n][np]) << el;
    return 0;
}
