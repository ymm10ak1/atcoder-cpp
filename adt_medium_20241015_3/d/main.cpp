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

bool solve(const vector<string>& s, int n){
    const char ca2[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    rep(i,n){
        if(s[i][0]!='H' && s[i][0]!='D' && s[i][0]!='C' && s[i][0]!='S') return false;
        bool ok = false;
        rep(j,13) if(s[i][1] == ca2[j]) ok = true;
        if(!ok) return false;
    }
    map<string,bool> mp;
    rep(i,n){
        if(mp[s[i]]) return false;
        else mp[s[i]] = true;
    }
    return true;
}

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    if(solve(s, n)) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
