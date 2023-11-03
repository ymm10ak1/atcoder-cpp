// E - Secret Number
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
    string s;
    cin >> s;
    map<int, bool> mp;
    rep(i, s.size()){
        if(s[i] == 'o') mp[i] = false;
    }
    int ans = 0;
    rep(i, 10000){
        rep(i, s.size()){
            if(s[i] == 'o') mp[i] = false;
        }
        string t = to_string(i);
        if(t.size() < 4){
            int diff_size = 4-t.size();
            rep(j, diff_size) t = '0'+t;
        }
        bool ng = false;
        rep(j, t.size()){
            int idx = t[j]-'0';
            if(s[idx] == 'x') ng = true;
            if(s[idx] == 'o') mp[idx] = true;
        }
        if(ng) continue;
        int cnt = 0;
        for(auto p : mp){
            if(p.second == true) cnt++;
        }
        if(cnt == mp.size()) ans++;
    }
    cout << ans << el;
    return 0;
}