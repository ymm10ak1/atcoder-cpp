// E
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
    map<char,int> mp;
    int n = s.size();
    rep(i,n) mp[s[i]]++;
    ll ans = 0;
    bool first = false;
    rep(i,n){
        if(mp[s[i]] > 0) mp[s[i]]--;
        if(mp[s[i]] == 0) mp.erase(s[i]);
        int m = n-1-i-mp[s[i]];
        ans += m;
        if(mp[s[i]]>0) first = true;
    }
    if(first) ans++;
    cout << ans << el;
    return 0;
}
