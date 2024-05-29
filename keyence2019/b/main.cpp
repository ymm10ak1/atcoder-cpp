// B - KEYENCE String
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

bool check(string s){
    return s == "keyence";
}

int main(){
    string s; cin >> s;
    bool ok = false;
    // kXXeyenceかどうか
    string s1 = s.substr(0,1);
    string s2 = s.substr((int)s.size()-6,6);
    if(check(s1+s2)) ok = true;
    // keXXyenceかどうか
    s1 = s.substr(0,2);
    s2 = s.substr((int)s.size()-5,5);
    if(check(s1+s2)) ok = true;
    // keyXXenceかどうか
    s1 = s.substr(0,3);
    s2 = s.substr((int)s.size()-4,4);
    if(check(s1+s2)) ok = true;
    // keyeXXnceかどうか
    s1 = s.substr(0,4);
    s2 = s.substr((int)s.size()-3,3);
    if(check(s1+s2)) ok = true;
    // keyenXXceかどうか
    s1 = s.substr(0,5);
    s2 = s.substr((int)s.size()-2,2);
    if(check(s1+s2)) ok = true;
    // keyencXXeかどうか
    s1 = s.substr(0,6);
    s2 = s.substr((int)s.size()-1,1);
    if(check(s1+s2)) ok = true;
    // keyenceXXかどうか
    s1 = s.substr(0,7);
    if(check(s1)) ok = true;
    // XXkeyenceかどうか
    s2 = s.substr((int)s.size()-7,7);
    if(check(s2)) ok = true;
    
    if(ok) cout << "YES" << el;
    else cout << "NO" << el;
    return 0;
}
