// D
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
    string s;
    cin >> s;
    map<char,vector<int>> mp;
    rep(i,s.size()) mp[s[i]].push_back(i);
    ll ans = 0;
    for(auto [k,v] : mp){
        int l = 0, r = v.size()-1;
        rep(i,v.size()){
            ans += (ll)l*v[i];
            ans -= (ll)r*v[i];
            l++, r--;
        }
        int n = v.size();
        ans -= (ll)n*(n-1)/2;
    }
    cout << ans << el;
    return 0;
}
