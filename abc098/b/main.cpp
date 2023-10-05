// B - Cut ans Count
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define REPI(i, s, n) for(int i=(int)(s); i<=(int)(n); ++i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0, n)
#define REPL(i, s, n) for(ll i=(s); i<=(ll)(n); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

vector<bool> alpha_check(string& t){
    vector<bool> alp(26, false);
    rep(i, t.size()){
        int idx = t[i]-97;
        alp[idx] = true;
    }
    return alp;
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i, n-1){
        string s1 = s.substr(0, i+1);
        string s2 = s.substr(i+1, s.size()-i-1);
        auto v1 = alpha_check(s1);
        auto v2 = alpha_check(s2);
        int v = 0;
        rep(i, v1.size()){
            if(v1[i] && v2[i]) ++v;
        }
        ans = max(ans, v);
    }
    cout << ans << el;
    return 0;
}