// C - Neo-lexicographic Ordering
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
    string x;
    int n;
    cin >> x >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    map<char,int> mp;
    rep(i,x.size()) mp[x[i]] = i;
    vector<pair<vector<int>,int>> vpv;
    rep(i,n){
        vector<int> v;
        rep(j,s[i].size()) v.push_back(mp[s[i][j]]);
        vpv.push_back({v,i});
    }
    sort(all(vpv));
    rep(i,vpv.size()) cout << s[vpv[i].second] << el;
    return 0;
}