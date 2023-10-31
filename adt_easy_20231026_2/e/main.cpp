// E - Poem Online Judge
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    int n;
    cin >> n;
    vector<pair<string, int>> st(n);
    rep(i, n) cin >> st[i].first >> st[i].second;
    map<string, int> mp;
    vector<pair<string, int>> v;
    rep(i, n){
        if(mp[st[i].first] == 0){
            mp[st[i].first] = i+1;
            v.push_back(make_pair(st[i].first, st[i].second));
        }
    }
    string max_s = v[0].first;
    int max_v = 0;
    rep(i, v.size()){
        if(v[i].second > max_v){
            max_v = v[i].second;
            max_s = v[i].first;
        }
    }
    cout << mp[max_s] << el;
    return 0;
}