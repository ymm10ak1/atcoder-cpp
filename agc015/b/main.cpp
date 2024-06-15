// B - EVilator
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
    // 今いる階が2階以上でUの場合、上の階にDがあれば下の階にもいける -> 制約よりs[s]がDであるため今いる階からそれ以外の階にいける
    // 今いる階が2階以上でDの場合、下の階にUがあれば上の階にもいける -> 制約よりs[0]がUであるため今いる階からそれ以外の階にいける
    int n = (int)s.size();
    ll ans = 0;
    rep(i,n){
        if(s[i] == 'U'){
            ans += n-i-1;
            if(i>0) ans += 2*i;
        }else if(s[i] == 'D'){
            ans += i;
            if(i < n-1) ans += 2*(n-i-1);
        }
    }
    cout << ans << el;
    return 0;
}
