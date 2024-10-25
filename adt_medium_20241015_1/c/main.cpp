// C
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
    string s; cin >> s;
    int n = s.size();
    string s1 = s+s;
    vector<string> ans;
    rep(i,n){
        string t = s1.substr(i,n);
        ans.push_back(t);
    }
    string s2 = s;
    reverse(all(s2));
    rep(i,n){
        s = s2[i]+s;
        string t = s.substr(0,n);
        ans.push_back(t);
    }
    sort(all(ans));
    cout << ans[0] << el;
    cout << ans[(int)ans.size()-1] << el;
    return 0;
}
