// C - One Time Swap
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
    vector<int> alp(26,0);
    rep(i,s.size()) alp[s[i]-97]++;
    ll ans = 0;
    bool same = false;
    rep(i,s.size()){
        alp[s[i]-97]--;
        rep(j,26){
            char c = 'a'+j;
            if(alp[j]>0 && s[i] != c) ans += alp[j];
            if(alp[j]>0 && s[i] == c){
                if(!same){ ans++; same = true; }
            }
        }
    }
    cout << ans << el;
    return 0;
}
