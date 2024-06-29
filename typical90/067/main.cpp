// 067 - Base 8 to 9（★2）
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

ull to10(string s){
    ull x10 = 0, p = 1;
    reverse(all(s));
    rep(i,s.size()){
        x10 += ((s[i]-'0')*p);
        p *= 8;
    }
    return x10;
}

string to9(ull x10){
    string s = "";
    while(x10 > 0){
        char c = x10%9;
        s += c+'0';
        x10 /= 9;
    }
    if(s == "") s = "0";
    rep(i,s.size()) if(s[i] == '8') s[i] = '5';
    reverse(all(s));
    return s;
}

int main(){
    string n;
    int k;
    cin >> n >> k;
    string ans = n;
    rep(i,k) ans = to9(to10(ans));
    cout << ans << el;
    return 0;
}
