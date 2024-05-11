// F - Rotate Colored Subsequence
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
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    vector<vector<int>> idx(m);
    vector<string> ss(m);
    rep(i,n){
        idx[c[i]%m].push_back(i);
        ss[c[i]%m] += s[i];
    }
    rep(i,m){
        if(ss[i].size() > 1){
            int ss_len = ss[i].size();
            string t = ss[i][ss_len-1]+ss[i];
            t = t.substr(0,ss_len);
            ss[i] = t;
        }
    }
    map<int, char> mp;
    rep(i,m){
        rep(j,idx[i].size()){
            mp[idx[i][j]] = ss[i][j];
        }
    }
    for(auto p : mp) cout << p.second;
    cout << el;
    return 0;
}