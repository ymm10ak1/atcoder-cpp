// 
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
    int n;
    cin >> n;
    vector<pair<int, int>> xy(n);
    rep(i, n) cin >> xy[i].second >> xy[i].first;
    string s;
    cin >> s;
    map<int, vector<pair<int, int>>> mp;
    rep(i, n) mp[xy[i].first].push_back({xy[i].second, i});
    for(auto p : mp){
        sort(all(p.second));
        string ss = "";
        rep(i, p.second.size()) ss += s[p.second[i].second];
        rep(i, ss.size()-1){
            if(ss[i]=='R' && ss[i+1]=='L'){
                cout << "Yes" << el;
                return 0;
            }
        }
    }
    cout << "No" << el;
    return 0;
}