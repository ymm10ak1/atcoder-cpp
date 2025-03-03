#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n, m;
    string s;
    cin >> n >> m >> s;
    int t = 0, ans = 0, mm = m;
    rep(i,n){
        if(s[i] == '1'){
            if(mm > 0) mm--;
            else t++;
        }else if(s[i] == '2'){
            t++;
        }else{
            ans = max(ans, t);
            t = 0;
            mm = m;
        }
    }
    ans = max(ans, t);
    cout << ans << el;
    return 0;
}
