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
    string s;
    cin >> n >> m >> s;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    map<int,vector<pair<int,char>>> mp;
    rep(i,n) mp[c[i]-1].emplace_back(i,s[i]);
    rep(i,m) mp[i].emplace_back(mp[i][0]);
    string ans = s;
    rep(i,m){
        rep(j,mp[i].size()-1){
            int idx = mp[i][j+1].first;
            char ch = mp[i][j].second;
            ans[idx] = ch;
        }
    }
    cout << ans << el;
    return 0;
}
