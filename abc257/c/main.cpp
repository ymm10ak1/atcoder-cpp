// C - Robot Takahashi
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
    vector<int> w(n);
    rep(i,n) cin >> w[i];
    map<int,vector<int>> mp;
    rep(i,n) mp[w[i]].push_back(i);
    int now = 0;
    rep(i,n) if(s[i] == '1') now++;
    int ans = now;
    for(auto [k,v] : mp){
        rep(i,v.size()){
            if(s[v[i]] == '0') now++;
            else now--;
        }
        ans = max(ans, now);
    }
    cout << ans << el;
    return 0;
}
