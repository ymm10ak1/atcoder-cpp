// F
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
    string s;
    cin >> n >> m >> s;
    vector<int> c(n);
    rep(i,n){
        cin >> c[i];
        c[i]--;
    }
    map<int,string> mp;
    map<int,vector<int>> idx;
    rep(i,n){
        mp[c[i]] += s[i];
        idx[c[i]].push_back(i);
    }
    for(auto p : mp){
        string t = p.second;
        t = p.second.back()+t;
        mp[p.first] = t;
    }
    rep(i,m){
        vector<int> idx2 = idx[i];
        rep(j,idx2.size()){
            s[idx2[j]] = mp[i][j];
        }
    }
    cout << s << el;
    return 0;
}
