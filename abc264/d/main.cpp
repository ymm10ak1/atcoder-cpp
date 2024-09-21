// D - "redocta".swap(i,i+1)
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
    vector<int> v(s.size());
    rep(i,s.size()){
        if(s[i] == 'a') v[i] = 0;
        else if(s[i] == 't') v[i] = 1;
        else if(s[i] == 'c') v[i] = 2;
        else if(s[i] == 'o') v[i] = 3;
        else if(s[i] == 'd') v[i] = 4;
        else if(s[i] == 'e') v[i] = 5;
        else if(s[i] == 'r') v[i] = 6;
    }
    vector<int> rshift(s.size());
    rep(i,v.size()-1){
        int cnt = 0;
        repi(j,i+1,v.size()) if(v[i] > v[j]) cnt++;
        rshift[i] = cnt;
    }
    int ans = 0;
    rep(i,s.size()){
        int pos = i+rshift[i];
        if(s[i] == 'a') pos -= 0;
        else if(s[i] == 't') pos -= 1;
        else if(s[i] == 'c') pos -= 2;
        else if(s[i] == 'o') pos -= 3;
        else if(s[i] == 'd') pos -= 4;
        else if(s[i] == 'e') pos -= 5;
        else if(s[i] == 'r') pos -= 6;
        ans += pos;
    }
    cout << ans << el;
    return 0;
}
