// D - LOWER
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
    int n, q;
    string s;
    cin >> n >> s >> q;
    map<int,char> mp;
    int lower = 0;
    rep(i,q){
        int t, x;
        char c;
        cin >> t >> x >> c;
        if(t == 1){
            s[x-1] = c;
            mp[x-1] = c;
        }else if(t == 2){
            lower = 1;
            mp = map<int,char>();
        }else{
            lower = 2;
            mp = map<int,char>();
        }
    }
    if(lower == 1){
        rep(i,s.size()) s[i] = tolower(s[i]);
        for(auto p : mp) s[p.first] = p.second;
    }else if(lower == 2){
        rep(i,s.size()) s[i] = toupper(s[i]);
        for(auto p : mp) s[p.first] = p.second;
    }
    cout << s << el;
    return 0;
}
