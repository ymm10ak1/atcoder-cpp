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
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int ans = 0;
    rep(biti, (1<<n)){
        int v = 0;
        map<char, int> mp;
        // n個の文字列から選ぶ
        rep(i, n){
            if(biti & (1<<i)){
                // 選んだ文字列の英小文字をカウントするJ
                rep(j, s[i].size()) ++mp[s[i][j]];
            }
        }
        for(auto p : mp) if(p.second == k) ++v;
        ans = max(ans, v);
    }
    cout << ans << el;
    return 0;
}