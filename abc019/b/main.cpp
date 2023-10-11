// B - 高橋君と文字列圧縮
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
    vector<pair<string, int>> a;
    for(int i=0; i<s.size();){
        int j=i;
        while(j<s.size() && s[j]==s[i]) ++j;
        string t = s.substr(i, 1);
        a.push_back(make_pair(t, j-i));
        i = j;
    }
    for(auto p : a){
        cout << p.first << p.second;
    }
    cout << el;
    return 0;
}