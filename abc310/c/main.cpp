// C - Reversible
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
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    map<string,int> mp; 
    rep(i,n){
        string ss = s[i];
        reverse(all(ss));
        if(mp[s[i]] || mp[ss]) continue;
        mp[s[i]] = 1;
    }
    int ans = 0;
    for(auto [k,v] : mp) if(v==1) ans++;
    cout << ans << el;
    return 0;
}
