// 
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

bool solve(){
    string s; cin >> s;
    if((int)s.size()%2 == 1) return false;
    map<char,int> mp;
    for(int i=0; i<(int)s.size()-1; i+=2){
        if(s[i] != s[i+1]) return false;
        if(s[i] == s[i+1]) mp[s[i]] += 2;
    }
    for(auto p : mp) if(p.second != 2) return false;
    return true;
}

int main(){
    if(solve()) cout << "Yes" << el;
    else cout << "No" << el;
    return 0;
}
