// A - ><
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
    cin >> s;
    vector<pair<char, ll>> p;
    for(int i=0; i<s.size();){
        int j = i;
        while(j<s.size() && s[j]==s[i]) ++j;
        p.push_back(make_pair(s[i], j-i));
        i = j;
    }
    ll ans = 0;
    for(int i=0; i<p.size();){
        char c = p[i].first;
        ll d = p[i].second;
        if(c == '<'){
            if(i == p.size()-1){
                ans += (d*(d+1)/2);
                i++;
            }else{
                // '>'の個数と比べる
                ll maxd = max(d, p[i+1].second);
                ll mind = min(d, p[i+1].second);
                mind--;
                ans += (maxd*(maxd+1)/2);
                ans += (mind*(mind+1)/2);
                i += 2;
            }
        }else{
            ans += (d*(d+1)/2);
            i++;
        }
    }
    cout << ans << el;
    return 0;
}