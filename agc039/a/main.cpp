// A - Connection and Disconnection
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repi(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define rrepi(i, n, s) for(int i=n-1; i>=s; --i)
#define repli(i, s, n) for(ll i=(s); i<(ll)(n); ++i)
#define repl(i, n) repli(i, 0LL, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
const int INF = 1e9;
const ll LINF = 1e18;

int main(){
    string s;
    int k;
    cin >> s >> k;
    vector<pair<char, int>> vp;
    string ss = s+s;
    for(int i=0; i<s.size();){
        int j = i;
        while(j<s.size() && s[i]==s[j]) ++j;
        vp.push_back(make_pair(s[i], j-i));
        i = j;
    }
    ll cnt = 0, ans = 0;
    if(vp.size() == 1){
        ans = ((ll)vp[0].second*k/2);
    }else{
        auto v0 = vp[0];
        auto vn = vp[vp.size()-1];
        if((v0.first == vn.first) && (v0.second%2==1) && (vn.second%2==1)){
            repi(i, 1, vp.size()-1) cnt += vp[i].second/2;
            int v0_cnt = v0.second/2;
            int vn_cnt = vn.second/2;
            ll v_zero_n = (ll)(v0.second+vn.second)/2*(k-1);
            ans = cnt*k+v0_cnt+vn_cnt+v_zero_n;
        }else{
            rep(i, vp.size()) cnt += vp[i].second/2;
            ans = cnt*k;
        }
    }
    cout << ans << el;
    return 0;
}