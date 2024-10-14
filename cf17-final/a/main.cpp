// A - AKIBA
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

const string A = "AKIHABARA";

bool solve(string& s){
    if(s.size() > A.size()) return false;
    if(s[0]!='A' && s[0]!='K') return false;
    if(s[0] == 'K') s = 'A'+s;
    if(s[s.size()-1] == 'R') s += 'A';
    rep(i,s.size()){
        if(s[i]=='H' || s[i]=='B'){
            if(i+1<(int)s.size() && s[i+1]!='A') s = s.substr(0,i+1)+'A'+s.substr(i+1);
        }
    }
    if(s != A) return false;
    return true;
}

int main(){
    string s; cin >> s;
    if(solve(s)) cout << "YES" << el;
    else cout << "NO" << el;
    return 0;
}
