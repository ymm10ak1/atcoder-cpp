// A - Prefix and Suffix
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
    int n;
    string s, t;
    cin >> n >> s >> t;
    if(s == t){
        cout << s.size() << el;
        return 0;
    }
    rep(i,s.size()){
        string ns = s.substr(0, i+1)+t;
        string ss = ns.substr(0, n);
        string tt = ns.substr(i+1, n);
        if(ss==s && tt==t){
            cout << ns.size() << el;
            return 0;
        }
    }
    return 0;
}
