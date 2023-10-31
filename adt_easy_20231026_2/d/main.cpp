// D - Longest Uncommon Prefix
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
    string s;
    cin >> n >> s;
    vector<int> ans;
    repi(i, 1, n){
        int cnt = 0;
        for(int j=0; j<n-i; ++j){
            if(s[j] == s[j+i]) break;
            if(s[j] != s[j+i]) cnt++;
        }
        ans.push_back(cnt);
    }
    for(auto v : ans){
        cout << v << el;
    }
    return 0;
}