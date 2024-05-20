// A - ><
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
    int l = 0, g = 0;
    ll ans = 0;
    rep(i,s.size()){
        if(i<(int)s.size()-1 && s[i]=='>' && s[i+1]=='<'){
            ++g;
            int maxCnt = max(l, g);
            int minCnt = min(l, g);
            --minCnt;
            ans += ((ll)maxCnt*(maxCnt+1)/2 + (ll)minCnt*(minCnt+1)/2);
            l = g = 0;
        }else if(s[i] == '<'){
            ++l;
        }else if(s[i] == '>'){
            ++g;
        }
        if(i==(int)s.size()-1 && (l>0 || g>0)){
            int maxCnt = max(l, g);
            int minCnt = min(l, g);
            --minCnt;
            ans += ((ll)maxCnt*(maxCnt+1)/2 + (ll)minCnt*(minCnt+1)/2);
        }
    }
    cout << ans << el;
    return 0;
}