// C - Cash Register
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
    ll cnt = 0, ans = 0;
    rep(i,s.size()){
        if(s[i] == '0'){
            cnt++;
        }else{
            ans++;
            if(cnt > 0){
                ans = cnt%2==1 ? ans+cnt/2+1 : ans+cnt/2;
                cnt = 0;
            }
        }
    }
    if(cnt > 0) ans = cnt%2==1 ? ans+cnt/2+1 : ans+cnt/2;
    cout << ans << el;
    return 0;
}
