// A - Non-Adjacent Flip
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
    int t; cin >> t;
    rep(i,t){
        int n;
        string s;
        cin >> n >> s;
        int cnt1 = 0;
        bool size3 = n<=3 ? true : false;
        bool ren = false;
        rep(j,n){
            if(j<n-1 && s[j]=='1' && s[j+1]=='1') ren = true;
            if(s[j] == '1') cnt1++;
        }
        bool ng = false;
        int ans = 0;
        // 1の個数が奇数ならng
        if(cnt1%2) ng = true;
        else ans = cnt1/2;
        if(cnt1 == 2){
            if(size3){
                // 1の個数が2個でnが4以下の場合、"011","110"はngとなる
                if(ren) ng = true;
            }else{
                // "0110"のときすべて裏向きになるのはcnt1/2+2回
                // 1の個数が2個でnが3より大きい場合、すべて裏向きにできるが回数を+1する
                if(s == "0110") ans += 2;
                else if(ren)ans++;
            }
        }
        if(ng) cout << -1 << el;
        else cout << ans << el;
    }
    return 0;
}
