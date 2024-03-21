// F - Collision 2
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
    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    string s; cin >> s;
    map<int, vector<pair<int,char>>> mp;
    rep(i,n){
        mp[y[i]].push_back({x[i],s[i]});
    }
    bool ok = false;
    for(auto p : mp){
        if(p.second.size() <= 1) continue;
        int first_R = -1;
        sort(all(p.second));
        rep(i,p.second.size()){
            if(p.second[i].second == 'R') first_R = i;
            if(first_R!=-1 && p.second[i].second=='L') ok = true;
        }
    }
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}