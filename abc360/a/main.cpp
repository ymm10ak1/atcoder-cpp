// A
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
    bool gohan = false;
    rep(i,s.size()){
        if(s[i] == 'R') gohan = true;
        if(s[i] == 'M'){
            if(gohan) cout << "Yes" << el;
            else cout << "No" << el;
            return 0;
        }
    }
    return 0;
}