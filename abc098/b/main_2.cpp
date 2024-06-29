// B - Cut and Count
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
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i,s.size()-1){
        string x = s.substr(0, i+1);
        string y = s.substr(i+1, n-(i+1));
        vector<bool> xa(26), ya(26);
        rep(j,x.size()) xa[x[j]-97] = true;
        rep(j,y.size()) if(xa[y[j]-97]) ya[y[j]-97] = true;
        int cnt = 0;
        rep(j,26) if(ya[j]) ++cnt;
        ans = max(ans, cnt);
    }
    cout << ans << el;
    return 0;
}
