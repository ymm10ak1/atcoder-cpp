// C - 一次元リバーシ
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
    char c = s.back();
    int ans = 0;
    // NOTE: 白と黒が変わるところの個数
    rrepi(i,s.size(),1){
        if(c != s[i-1]){
            c = s[i-1];
            ans++;
        }
    }
    cout << ans << el;
    return 0;
}
