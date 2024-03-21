// C - 1-SAT
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
    vector<string> s(n);
    map<string, bool> mp;
    rep(i,n){
        cin >> s[i];
        mp[s[i]] = true;
    }
    rep(i,n){
        string t = "";
        if(s[i][0] == '!'){
            t = s[i].substr(1);
        }else{
            t = s[i];
        }
        if(mp[t] && mp["!"+t]){
            cout << t << el;
            return 0;
        }
    }
    cout << "satisfiable" << el;
    return 0;
}