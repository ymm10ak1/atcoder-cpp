// A - Shrinking
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

int alp[26];

int main(){
    string s; cin >> s;
    rep(i,s.size()) alp[s[i]-97]++;
    vector<pair<int,char>> vp;
    rep(i,26) if(alp[i] > 0) vp.push_back({alp[i], 'a'+i});
    sort(rall(vp));
    int n = s.size();
    int ans = n/2;
    rep(i,vp.size()){
        if(vp[i].first > 1){
            int cnt = 0, v = 0;
            rep(j,s.size()){
                if(s[j] == vp[i].second){
                    v = max(v, cnt);
                    cnt = 0;
                }else{
                    cnt++;
                }
            }
            v = max(v, cnt);
            ans = min(ans, v);
        }
    }
    cout << ans << el;
    return 0;
}
