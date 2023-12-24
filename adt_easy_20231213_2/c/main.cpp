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
    int n, d;
    cin >> n >> d;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int renzoku = 0;
    int ans = 0;
    rep(i, d){
        int cnt = 0;
        rep(j, n){
            if(s[j][i] == 'o'){
                ++cnt;
            }else{
                cnt = 0;
            }
        }
        if(cnt == n) ++renzoku;
        else renzoku = 0;
        ans = max(ans, renzoku);
    }
    cout << ans << el;
    return 0;
}