#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
#define repi(i, s, n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrep(i, n, s) for(int i = (int)(n)-1; i >= (int)(s); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'
const int INF = 1e9;
const ll LLINF = 1e18;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    char c0 = '0', c1 = '1';
    vector<int> a0(n), a1(n), b0(n), b1(n); 
    rep(i,n){
        a0[i] = c0==s[i]?0:c[i];
        b0[i] = c0-'0';
        c0 = c0=='0'?'1':'0';
        a1[i] = c1==s[i]?0:c[i];
        b1[i] = c1-'0';
        c1 = c1=='1'?'0':'1';
    }
    vector<ll> s0(n+1), s1(n+1);
    rep(i,n){
        s0[i+1] = s0[i]+a0[i];
        s1[i+1] = s1[i]+a1[i];
    }
    ll ans = LLINF;
    rep(i,n-1){
        ll now = 0;
        // 00にする
        if(s[i] != '0') now += c[i];
        if(s[i+1] != '0') now += c[i+1];
        if(i-1 >= 0){
            if(b0[i-1] == 1) now += s0[i];
            else if(b1[i-1] == 1) now += s1[i];
        }
        if(i+2 < n){
            if(b0[i+2] == 1) now += s0[n]-s0[i+2];
            else if(b1[i+2] == 1) now += s1[n]-s1[i+2];
        }
        ans = min(ans, now);
        now = 0;
        // 11にする
        if(s[i] != '1') now += c[i];
        if(s[i+1] != '1') now += c[i+1];
        if(i-1 >= 0){
            if(b0[i-1] == 0) now += s0[i];
            else if(b1[i-1] == 0) now += s1[i];
        }
        if(i+2 < n){
            if(b0[i+2] == 0) now += s0[n]-s0[i+2]; 
            else if(b1[i+2] == 0) now += s1[n]-s1[i+2];
        }
        ans = min(ans, now);
    }
    cout << ans << el;
    return 0;
}
