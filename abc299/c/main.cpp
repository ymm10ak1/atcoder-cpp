// C - Dango
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
    int n;
    string s;
    cin >> n >> s;
    vector<pair<char,int>> vp;
    int i = 0;
    while(i < n){
        int j = i+1;
        while(j<n && s[i]==s[j]) ++j;
        vp.emplace_back(s[i], j-i);
        i = j;
    }
    int ans = -1;
    if(vp.size() > 1){
        rep(k,vp.size()) if(vp[k].first == 'o') ans = max(ans, vp[k].second);
    }
    cout << ans << el;
    return 0;
}
