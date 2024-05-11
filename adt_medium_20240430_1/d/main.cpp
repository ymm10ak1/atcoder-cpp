// D - Frequency
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

int cnt[26];

int main(){
    string s; cin >> s;
    rep(i,s.size()) ++cnt[s[i]-97];
    int cur = 0;
    char ans = 'a';
    rep(i,26){
        if(cnt[i] > cur){
            cur = cnt[i];
            ans = 97+i;
        }
    }
    cout << ans << el;
    return 0;
}