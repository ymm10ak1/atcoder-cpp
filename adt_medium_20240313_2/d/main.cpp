// 
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
    string s; cin >> s;
    vector<pair<char,int>> vp;
    string ns="";
    if(s.size()>1){
        rep(i,s.size()-1){
            while(s[i] == s[i+1]) ++i;
            ns += s[i];
        }
        if(s[s.size()-2] != s[s.size()-1]) ns += s[s.size()-1];
    }else{
        ns = s;
    }
    bool ok = false;
    if(ns == "ABC") ok = true;
    else if(ns == "A") ok = true;
    else if(ns == "AB") ok = true;
    else if(ns == "AC") ok = true;
    else if(ns == "B") ok = true;
    else if(ns == "BC") ok = true;
    else if(ns == "C") ok = true;
    else if(ns == "") ok = true;
    if(ok) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}