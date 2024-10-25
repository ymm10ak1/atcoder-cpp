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
    string s, t;
    cin >> s >> t;
    vector<string> ans;
    while(1){
        vector<string> ns;
        rep(j,s.size()){
            if(s[j] != t[j]){
                string ss = s;
                ss[j] = t[j];
                ns.push_back(ss);
            }
        }
        if(ns.size() > 0){
            sort(all(ns));
            s = ns[0];
            ans.push_back(s);
        }
        if(s == t) break;
    }
    cout << ans.size() << el;
    for(string word : ans) cout << word << el;
    return 0;
}
