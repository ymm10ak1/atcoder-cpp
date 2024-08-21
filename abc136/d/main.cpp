// D - Gathering Children
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
    int n = s.size();
    // ランレングス圧縮
    vector<pair<char, int>> vp;
    vector<int> idx;
    int i = 0;
    while(i < n){
        int j = i+1;
        while(j<n && s[i]==s[j]) ++j;
        vp.push_back({s[i], j-i});
        if(s[i]=='R') idx.push_back(j-1);
        else idx.push_back(i);
        i = j;
    }
    vector<int> ans(n, 0);
    rep(i,vp.size()){
        if(vp[i].first == 'L') continue;
        int rl = vp[i].second+vp[i+1].second;
        if(rl % 2){
            if(vp[i].second < vp[i+1].second){
                ans[idx[i]] = rl/2;
                ans[idx[i+1]] = rl-rl/2;
            }else{
                ans[idx[i]] = rl-rl/2;
                ans[idx[i+1]] = rl/2;
            }
            int mn = min(vp[i].second, vp[i+1].second);
            if(mn % 2) swap(ans[idx[i]], ans[idx[i+1]]);
        }else{
            ans[idx[i]] = ans[idx[i+1]] = rl/2;
        }
    }
    rep(i,n) printf("%d%c", ans[i], i==n-1?'\n':' ');
    return 0;
}
